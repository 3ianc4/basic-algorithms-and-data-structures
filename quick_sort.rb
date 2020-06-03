require "test/unit/assertions"
include Test::Unit::Assertions

def swap array, left_pointer, right_pointer
    temp = array[left_pointer]
    array[left_pointer] = array[right_pointer]
    array[right_pointer] = temp
    array
end

def quick_sort array
    return array if array.size == 1 || array.size == 0
    pivot = array[array.size-1]
    right_pointer = 0

    for left_pointer in 0..array.size-2
        if array[left_pointer] <= pivot
            array = swap(array, left_pointer, right_pointer)
            right_pointer += 1
        end
    end
    array = swap(array, array.size-1, right_pointer)
    

    left = if right_pointer == 0
        quick_sort([])
    else
        quick_sort(array[0...right_pointer])
    end

    right = quick_sort(array[right_pointer + 1...array.size])
    return left
        .concat([pivot])
        .concat(right)
end

assert_equal quick_sort([2, 1]), [1, 2]
assert_equal quick_sort([1, 2]), [1, 2]
assert_equal quick_sort([3, 2, 1]), [1, 2, 3]
assert_equal quick_sort([3, 1, 2]), [1, 2, 3]
assert_equal quick_sort([2, 1, 3]), [1, 2, 3]
assert_equal quick_sort([5, 6, 7, 8]), [5, 6, 7, 8]
assert_equal quick_sort([8, 7, 6, 5]), [5, 6, 7, 8]
assert_equal quick_sort([6, 8, 7, 5]), [5, 6, 7, 8]
