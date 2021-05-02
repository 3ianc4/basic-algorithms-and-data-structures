ExUnit.start()

defmodule SelectionSortTest do
  Code.compile_file("selection_sort.ex")
  use ExUnit.Case

  test "returns sorted list" do
    assert SelectionSort.selection_sort([5, 3, 1, 2, 0, 4]) == [0, 1, 2, 3, 4, 5]
  end

end
