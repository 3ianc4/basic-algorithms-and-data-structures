require "test/unit/assertions"
include Test::Unit::Assertions

def factorial(n, dictionary = { 1 => 1})
    if dictionary.has_key? n
        return dictionary[n]
    else
        result = n * (factorial(n-1))
        dictionary[n] = result
        return result
    end
end
assert_equal factorial(1), 1
assert_equal factorial(2), 2
assert_equal factorial(5), 120
assert_equal factorial(6), 720
