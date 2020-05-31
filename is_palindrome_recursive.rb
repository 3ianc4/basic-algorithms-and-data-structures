require "test/unit/assertions"
include Test::Unit::Assertions

def to_char(string)
    string = string.downcase.chars
    string = string.keep_if {|c| c =~ /[abcdefghijklmnopqrstuvwxyz]/ }.join
    is_palindrome(string)
end
def is_palindrome(string)
    if string.size == 1 || string.size == 0
        return true
    else
        string[0] == string[-1] and is_palindrome(string.slice(1...-1))
    end
end

assert_equal to_char("abba"), true
assert_equal to_char("abbas"), false
assert_equal to_char("tattarrattat"), true
assert_equal to_char("Was it a palindrome?"), false
assert_equal to_char("No lemon, no melon"), true
