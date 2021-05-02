defmodule SelectionSort do
  @moduledoc """
  Selection sort is an algotithm that sorts a list finding the
  lowest value and positioning in the first place of the list.
  """
  def selection_sort([]), do: []
  def selection_sort(list) do
    lowest = find_lowest(list)
    [lowest] ++ selection_sort(List.delete(list, lowest))
  end

  defp find_lowest(list) do
    Enum.min(list)
  end
end
