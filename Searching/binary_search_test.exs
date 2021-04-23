ExUnit.start()

defmodule BinarySearchTest do
  Code.compile_file("binary_search.ex")
  use ExUnit.Case

  test "returns position in list when valid target is given" do
    assert BinarySearch.binary_search([1, 2, 3, 4], 1) == 0
  end
  test "returns nil when invalid target is given" do
    assert BinarySearch.binary_search([1, 2, 3, 4], 5) == nil
  end

end
