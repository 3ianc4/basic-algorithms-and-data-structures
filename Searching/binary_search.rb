require "test/unit/assertions"
include Test::Unit::Assertions

def binary_search array, target
    left = 0
    right = array.size-1

    loop do
        pointer = (left + right)/2.floor
        if array[pointer] == target
            return pointer
            break
        elsif array[pointer] > target
            right = pointer - 1
        elsif array[pointer] < target
            left = pointer + 1
        end
        if left > right
            return false
            break
        end
    end
end

assert_equal binary_search([1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 22, 33, 34, 35, 36, 77, 101, 1000, 10003], 9), 8
assert_equal binary_search([1, 2, 3, 4, 5, 6, 7, 8, 9, 10], 11), false
assert_equal binary_search([1, 2, 3, 4, 5, 6, 7, 8, 9, 10], 10), 9
assert_equal binary_search([0.33, 0.34, 0.99, 1, 2, 3], 2), 4
assert_equal binary_search([1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 22, 33, 34, 35, 36, 77, 101, 1000, 10003], 11), 9
