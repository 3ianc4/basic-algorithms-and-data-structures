require "test/unit/assertions"
include Test::Unit::Assertions

def merge_sort array
    if array.size <= 1
        return array
    else
        mid = array.size/2
        left = merge_sort(array[0...mid])
        right = merge_sort(array[mid..array.size])
        merge(left, right)
    end
end

def merge left, right
    if left.empty?
        return right
    elsif right.empty?
        return left
    elsif left.first < right.first
        return [left.first] + merge(left[1..left.size], right)
    else
        return [right.first] + merge(left, right[1..right.size])
    end
end
p merge_sort([5, 2, 1 , 3])

assert_equal merge_sort([1, 1, 1, 1, 1, 1, 1]), [1, 1, 1, 1, 1, 1, 1]
assert_equal merge_sort([1, 2, 3, 4, 5, 6, 7]), [1, 2, 3, 4, 5, 6, 7]
assert_equal merge_sort([7, 6, 5, 4, 3, 2, 1]), [1, 2, 3, 4, 5, 6, 7]
assert_equal merge_sort([3, 2, 5, 6, 4, 7, 1]), [1, 2, 3, 4, 5, 6, 7]
