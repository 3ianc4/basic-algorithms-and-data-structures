require "test/unit/assertions"
include Test::Unit::Assertions

def to_char(string)
    string = string.downcase.chars
    string = string.keep_if {|c| c =~ /[abcdefghijklmnopqrstuvwxyz]/ }.join
    is_palindrome(string)
end
def is_palindrome(string)
    i = string.size-1
    reversed = ""
    while i >= 0
        reversed << string[i]
        i -= 1
    end
    reversed == string ? true : false
end
assert_equal to_char("abba"), true
assert_equal to_char("abbas"), false
assert_equal to_char("tattarrattat"), true
assert_equal to_char("Was it a palindrome?"), false
assert_equal to_char("No lemon, no melon"), true