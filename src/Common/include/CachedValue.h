// Common: CachedValue.h
// A basic template class for calculating and storing a cached value.

namespace Biendeo::AdventOfCode2017 {
	/// Stores a value and returns the cached value until manually invalidated.
	template <typename T>
	class CachedValue {
		public:
		CachedValue() {
			calculated = false;
		}

		/// Gets the value, and if it's not calculated already, runs the given function, stores the
		/// returning result, and returns that.
		/// Generally, you would wrap this function with a public function so that you can call a
		/// specific function underneath.
		template <typename U>
		T Get(U&& func) const {
			if (!calculated) {
				value = func();
				calculated = true;
			}
			return value;
		}

		/// Invalidates the stored value, requiring a run of the function next time.
		void Invalidate() const {
			calculated = false;
		}

		private:
		mutable bool calculated;
		mutable T value;
	};
}