// Day 7: RecursiveCircus.cpp
// Definitions for the class that recreates a tree.

#include "RecursiveCircus.h"

#include <fstream>
#include <iostream>
#include <queue>

#include "StringFunctions.h"

Biendeo::AdventOfCode2017::Day7::RecursiveCircus::RecursiveCircus(const std::string& inputFile) {
	std::ifstream f(inputFile);
	std::string line;

	// This struct will be useful for storing basic information.
	struct NodeInfo {
		std::string name;
		int value;
		std::vector<std::string> children;
	};

	std::queue<NodeInfo> waitingNodes;

	while (std::getline(f, line)) {
		auto lineSplit = Split(line, ' ');
		struct NodeInfo thisNode;
		// The first part is always the node's name.
		thisNode.name = lineSplit[0];
		// The second part is the weight in brackets. Cut out the first and last characters to get
		// it.
		thisNode.value = std::stoi(lineSplit[1].substr(1, lineSplit[1].size() - 2));
		// The third part is an arrow if the node has any children. We check that the vector keeps
		// going on.
		if (lineSplit.size() > 2) {
			// For any name that's not the last one, it has a trailing comma, so we cut that off.
			for (size_t pos = 3; pos < lineSplit.size() - 1; ++pos) {
				thisNode.children.push_back(lineSplit[pos].substr(0, lineSplit[pos].size() - 1));
			}
			// The last child won't have a comma, so no cutting needs to happen.
			thisNode.children.push_back(lineSplit[lineSplit.size() - 1]);
		}
		waitingNodes.push(thisNode);
	}

	// Now we need to put every node in the graph. Let's run through the queue multiple times,
	// removing elements from it and adding them to the graph if every one of their children
	// exist in the graph.
	while (!waitingNodes.empty()) {
		NodeInfo currentNode = waitingNodes.front();
		waitingNodes.pop();
		bool allChildrenIn = true;
		for (const std::string& childName : currentNode.children) {
			if (nodes.find(childName) == nodes.end()) {
				allChildrenIn = false;
				break;
			}
		}
		// If all the children existed, set up the node.
		if (allChildrenIn) {
			auto newNode = std::make_shared<TreeNode<std::string, int>>(currentNode.name, currentNode.value);
			for (const std::string& childName : currentNode.children) {
				std::shared_ptr<TreeNode<std::string, int>> child = nodes[childName];
				child->SetParent(newNode);
				newNode->AddChild(child);
			}
			nodes.insert(std::pair<std::string, std::shared_ptr<TreeNode<std::string, int>>>(currentNode.name, newNode));
		} else {
			// Otherwise, add it back into the queue.
			waitingNodes.push(currentNode);
		}
	}

	f.close();
}

std::string Biendeo::AdventOfCode2017::Day7::RecursiveCircus::RootName() {
	return rootNameCache.Get([&] {
		return CalculateRootName();
	});
}

int Biendeo::AdventOfCode2017::Day7::RecursiveCircus::IncorrectWeight() {
	return incorrectWeightFixCache.Get([&] {
		return CalculateIncorrectWeight();
	});
}

std::string Biendeo::AdventOfCode2017::Day7::RecursiveCircus::CalculateRootName() {
	// To do this, we just pick any node and follow its parents until we reach nullptr.
	std::shared_ptr<TreeNode<std::string, int>> currentNode = (*nodes.begin()).second;
	while (currentNode->Parent() != nullptr) {
		currentNode = currentNode->Parent();
	}
	return currentNode->Name();
}

int Biendeo::AdventOfCode2017::Day7::RecursiveCircus::CalculateIncorrectWeight() {
	// The incorrect value can be found once all the children in the currentNode have the same
	// weight.
	std::shared_ptr<TreeNode<std::string, int>> currentNode = nodes[RootName()];
	bool allChildrenSame = false;
	while (!allChildrenSame) {
		if (currentNode->Children().size() < 2) {
			// If the node doesn't have enough children, then this node is the culprit.
			allChildrenSame = true;
			break;
		} else {
			std::map<int, int> weightFrequencies;
			for (auto& child : currentNode->Children()) {
				int weight = child->RecursiveWeight();
				if (weightFrequencies.find(weight) != weightFrequencies.end()) {
					weightFrequencies[weight] += 1;
				} else {
					weightFrequencies.insert(std::pair<int, int>(weight, 1));
				}
			}
			if (weightFrequencies.size() == 1) {
				allChildrenSame = true;
				break;
			} else {
				int correctWeight;
				int incorrectWeight;
				for (auto& weight : weightFrequencies) {
					if (weight.second != 1) {
						correctWeight = weight.first;
					} else {
						incorrectWeight = weight.first;
					}
				}
				for (auto& child : currentNode->Children()) {
					if (child->RecursiveWeight() == incorrectWeight) {
						currentNode = child;
						break;
					}
				}
			}
		}
	}
	// Now currentNode is the culprit node. We just need to find what value it should be. Let's
	// figure this out with its parent node. We just do the same process to find which node is
	// the odd one out.
	currentNode = currentNode->Parent();
	std::map<int, int> weightFrequencies;
	for (auto& child : currentNode->Children()) {
		int weight = child->RecursiveWeight();
		if (weightFrequencies.find(weight) != weightFrequencies.end()) {
			weightFrequencies[weight] += 1;
		} else {
			weightFrequencies.insert(std::pair<int, int>(weight, 1));
		}
	}
	int correctWeight;
	int incorrectWeight;
	for (auto& weight : weightFrequencies) {
		if (weight.second != 1) {
			correctWeight = weight.first;
		} else {
			incorrectWeight = weight.first;
		}
	}
	for (auto& child : currentNode->Children()) {
		if (child->RecursiveWeight() == incorrectWeight) {
			return correctWeight - incorrectWeight + child->Weight();
		}
	}
	
	// If you reach here, something messed up.
	return -1;
}
