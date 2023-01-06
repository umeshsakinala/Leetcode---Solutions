class Solution:
    def maxIceCream(self, costs: List[int], coins: int) -> int:
        costs.sort()
        coins_sum = list(accumulate(costs))
        return bisect_right(coins_sum, coins)

