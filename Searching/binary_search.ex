defmodule BinarySearch do
  def binary_search(list, target) do
    low = 0
    high = length(list) - 1

    search(list, target, low, high)
  end

  def search(_list, _target, low, high) when high < low, do: nil
  def search(list, target, low, high) do
    middle_item = div((low + high), 2)
    attempt = Enum.at(list, middle_item)
    cond do
      attempt == target -> middle_item
      attempt > target -> search(list, target, low, middle_item - 1)
      attempt < target -> search(list, target, middle_item + 1, high)
    end
  end
end
