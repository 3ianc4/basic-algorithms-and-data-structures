require "test/unit/assertions"
include Test::Unit::Assertions

def swap(array, left_pointer, right_pointer)
    temp = array[right_pointer]
    array[right_pointer] = array[left_pointer]
    array[left_pointer] = temp
end
def insertion_sort(array)
    for i in 0...array.size
        left_pointer = i
        right_pointer = i - 1
        while left_pointer > 0 && array[right_pointer] > array[left_pointer]
            swap(array, left_pointer, right_pointer)
            right_pointer -= 1
            left_pointer -= 1
        end
    end
    return array
end

assert_equal insertion_sort([1, 2, 3, 4, 5, 6, 7, 8]), [1, 2, 3, 4, 5, 6, 7, 8]
assert_equal insertion_sort([8, 7, 6, 5, 4, 3, 2, 1]), [1, 2, 3, 4, 5, 6, 7, 8]
assert_equal insertion_sort([3, 8, 5, 6, 4, 1, 7, 2]), [1, 2, 3, 4, 5, 6, 7, 8]
assert_equal insertion_sort([1, 1, 1, 1, 1, 1, 1, 1]), [1, 1, 1, 1, 1, 1, 1, 1]
assert_equal insertion_sort([1]), [1]

