main :: IO ()
main = print solve

solve :: Integer
solve = foldl1 lcm [1..20]
