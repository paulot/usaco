"""
Imagine that you have an histogram stored in an array. Now imagine that you can pour water on top of your histogram. Describe an algorithm that computes the amount of water that remains trapped among the columns of the graph. Clearly on the edges the water would fall off. Use the language or the pseudocode you prefer.
"""

def area(hists):
  i = 1;
  while (hists[i-1] < hists[i]) i += 1;
  min_bar = hists[i];
  max_bar = hists[i-1]

