require "test/unit/assertions"
include Test::Unit::Assertions

def fibonacci(n, dictionary = { 1 => 1, 2 => 1 })
    if n <=0
        return "Invalid number"
    elsif dictionary.has_key? n
        return dictionary[n]
    else
        result = fibonacci(n-1) + fibonacci(n-2)
        dictionary[n] = result
        return result
    end
end
assert_equal fibonacci(1), 1
assert_equal fibonacci(3), 2
assert_equal fibonacci(13), 233
assert_equal fibonacci(17), 1597
assert_equal fibonacci(-2), "Invalid number"