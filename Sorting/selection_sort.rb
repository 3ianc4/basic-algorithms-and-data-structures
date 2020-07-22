require "test/unit/assertions"
include Test::Unit::Assertions

def swap(i, pointer, array)
    if array[i] > array[pointer]
        temp = array[i]
        array[i] = array[pointer]
        array[pointer] = temp
    end
end
def selection_sort array
    for i in 0...array.size
        pointer = i
        for j in (pointer + 1)...array.size
            if array[j] < array[pointer]
                pointer = j
            end
        end
        swap(i, pointer, array)
    end
    return array
end
assert_equal selection_sort([1, 2, 3, 4, 5]), [1, 2, 3, 4, 5]
assert_equal selection_sort([5, 4, 3, 2, 1]), [1, 2, 3, 4, 5]
assert_equal selection_sort([4, 3, 5, 1, 2]), [1, 2, 3, 4, 5]
assert_equal selection_sort([1, 1, 1, 1, 1]), [1, 1, 1, 1, 1]
assert_equal selection_sort([10003, 7, 22, 99, 35, 1012, 1]), [1, 7, 22, 35, 99, 1012, 10003]
