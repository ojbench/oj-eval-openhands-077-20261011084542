namespace sjtu {
    class CrossArray {
    private:
        int** arrays;        // Array of pointers to int arrays
        int* sizes;          // Array storing size of each row
        int capacity;        // Maximum number of rows
        int current_lines;   // Current number of rows with data

    public:
        explicit CrossArray(int lines);
        CrossArray(const CrossArray& o);
        CrossArray& WhichGreater(CrossArray& o);
        bool IsSame(const CrossArray& o);
        bool InsertArrays(const int* Input, int size);
        void AppendArrays(const int* Input, int Line, int size);
        void DoubleCrossLength();
        const int* AtArray(int i);
        int& At(int i, int j);
        ~CrossArray();
    };

    // Constructor
    CrossArray::CrossArray(int lines) : capacity(lines), current_lines(0) {
        arrays = new int*[capacity];
        sizes = new int[capacity];
        for (int i = 0; i < capacity; i++) {
            arrays[i] = nullptr;
            sizes[i] = 0;
        }
    }

    // Copy Constructor
    CrossArray::CrossArray(const CrossArray& o) : capacity(o.capacity), current_lines(o.current_lines) {
        arrays = new int*[capacity];
        sizes = new int[capacity];
        
        for (int i = 0; i < capacity; i++) {
            if (o.arrays[i] != nullptr) {
                sizes[i] = o.sizes[i];
                arrays[i] = new int[sizes[i]];
                for (int j = 0; j < sizes[i]; j++) {
                    arrays[i][j] = o.arrays[i][j];
                }
            } else {
                arrays[i] = nullptr;
                sizes[i] = 0;
            }
        }
    }

    // Destructor
    CrossArray::~CrossArray() {
        for (int i = 0; i < capacity; i++) {
            if (arrays[i] != nullptr) {
                delete[] arrays[i];
                arrays[i] = nullptr;
            }
        }
        delete[] arrays;
        delete[] sizes;
    }

    // InsertArrays function
    bool CrossArray::InsertArrays(const int* Input, int size) {
        if (current_lines >= capacity) {
            return false;
        }
        
        arrays[current_lines] = new int[size];
        sizes[current_lines] = size;
        
        for (int i = 0; i < size; i++) {
            arrays[current_lines][i] = Input[i];
        }
        
        current_lines++;
        return true;
    }

    // At function - element access
    int& CrossArray::At(int i, int j) {
        return arrays[i][j];
    }

    // WhichGreater function
    CrossArray& CrossArray::WhichGreater(CrossArray& o) {
        int this_total = 0;
        int o_total = 0;
        
        for (int i = 0; i < current_lines; i++) {
            this_total += sizes[i];
        }
        
        for (int i = 0; i < o.current_lines; i++) {
            o_total += o.sizes[i];
        }
        
        if (o_total > this_total) {
            return o;
        } else {
            return *this;
        }
    }

    // IsSame function - check if objects refer to same memory space
    bool CrossArray::IsSame(const CrossArray& o) {
        return (this == &o);
    }

    // AppendArrays function
    void CrossArray::AppendArrays(const int* Input, int Line, int size) {
        int old_size = sizes[Line];
        int new_size = old_size + size;
        
        int* new_array = new int[new_size];
        
        // Copy old elements
        for (int i = 0; i < old_size; i++) {
            new_array[i] = arrays[Line][i];
        }
        
        // Copy new elements
        for (int i = 0; i < size; i++) {
            new_array[old_size + i] = Input[i];
        }
        
        // Delete old array and update
        delete[] arrays[Line];
        arrays[Line] = new_array;
        sizes[Line] = new_size;
    }

    // AtArray function
    const int* CrossArray::AtArray(int i) {
        return arrays[i];
    }

    // DoubleCrossLength function
    void CrossArray::DoubleCrossLength() {
        int new_capacity = capacity * 2;
        
        int** new_arrays = new int*[new_capacity];
        int* new_sizes = new int[new_capacity];
        
        // Copy existing arrays
        for (int i = 0; i < capacity; i++) {
            new_arrays[i] = arrays[i];
            new_sizes[i] = sizes[i];
        }
        
        // Initialize new positions
        for (int i = capacity; i < new_capacity; i++) {
            new_arrays[i] = nullptr;
            new_sizes[i] = 0;
        }
        
        // Delete old arrays and update
        delete[] arrays;
        delete[] sizes;
        arrays = new_arrays;
        sizes = new_sizes;
        capacity = new_capacity;
    }
}

// Main function for OJ compilation
int main() {
    return 0;
}

