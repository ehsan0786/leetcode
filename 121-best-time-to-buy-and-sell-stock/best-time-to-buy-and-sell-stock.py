class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        max_profit = 0
        minimum_price = prices[0]

        for price in prices[1:]:
            profit = price - minimum_price
            if profit > max_profit:
                max_profit = profit
            if price < minimum_price:
                minimum_price = price
        return max_profit
        