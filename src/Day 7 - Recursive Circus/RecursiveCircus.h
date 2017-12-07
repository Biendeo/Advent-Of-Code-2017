// Day 7: Recursive Circus
// Declarations for the class that recreates a tree.

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "CachedValue.h"

namespace Biendeo::AdventOfCode2017::Day7 {
	class RecursiveCircus {
		public:
		/// Constructs a RecursiveCircus with the given input file.
		RecursiveCircus(const std::string& inputFile);

		/// Returns the name of the root node.
		std::string RootName();

		/// Returns the value what the incorrect weight should be.
		int IncorrectWeight();

		private:
		template <typename T, typename U>
		class TreeNode {
			public:
			TreeNode(const T& name, const U& weight) {
				this->name = name;
				this->weight = weight;
				parent = std::shared_ptr<TreeNode>(nullptr);
			}

			T Name() const {
				return name;
			}

			U Weight() const {
				return weight;
			}

			U RecursiveWeight() const {
				U weightTotal = 0;
				for (auto& child : children) {
					weightTotal += child.lock()->RecursiveWeight();
				}
				return weight + weightTotal;
			}

			int Depth() const {
				if (parent.lock() == nullptr) {
					return 0;
				} else {
					return parent.lock()->Depth() + 1;
				}
			}

			std::shared_ptr<TreeNode<T, U>> Parent() const {
				return parent.lock();
			}

			std::vector<std::shared_ptr<TreeNode>> Children() const {
				std::vector<std::shared_ptr<TreeNode>> r;
				for (auto& child : children) {
					r.push_back(child.lock());
				}
				return r;
			}

			void SetParent(const std::shared_ptr<TreeNode> parent) {
				this->parent = parent;
			}

			void AddChild(const std::shared_ptr<TreeNode> child) {
				children.push_back(child);
			}

			private:
			T name;
			U weight;

			std::weak_ptr<TreeNode<T, U>> parent;
			std::vector<std::weak_ptr<TreeNode<T, U>>> children;
		};

		CachedValue<std::string> rootNameCache;
		CachedValue<int> incorrectWeightFixCache;

		/// Calculates the name of the root object in the tree.
		std::string CalculateRootName();

		/// Calculates the value that the incorrect weight should be.
		int CalculateIncorrectWeight();

		/// Stores all the tree's nodes in here. The tree is inside the data structure.
		std::map<std::string, std::shared_ptr<TreeNode<std::string, int>>> nodes;
	};
}