-- NOTES ON HASKELL WITH EXAMPLE CODE:

  -- > Imperative languages use brackets (()) to denote function application, functional languages
  -- like Haskell use spaces (  )

  -- > When using conditionals, you need an else statement to finish ifs

  -- > 65 :: Int  -> gives 65 as the type Int

  -- > You can use let to define a variable and load it in ghci

  -- > "hello" is just syntactic sugar for ["h","e","l","l","o"]
  -- > This means list operations can be used on strings

  --
  --       head                                      tail
  --   |`````````|      |``````````````````````````````````````````````````````````````|
  --     |-----|          |-----|           |-----|          |-----|          |-----|
  --     |--3--|   --->   |--9--|    --->   |--5--|   --->   |--1--|   --->   |--4--|
  --     |-----|          |-----|           |-----|          |-----|          |-----|
  --   |,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,|  |,,,,,,,,,,|
  --                           init                                             last
  --
  --    ^^ for list comprehension functions

-- doubles a given number, x
-- e.g. double 10 -> 20

double x = x + x

-- quadruples a given number, x
-- e.g. quadruple 100 -> 400

quadruple x = double (double x)

-- calculates factorial of a given number
-- e.g. factorial 5 -> 120

factorial n = product [1..n]

-- computes an average from a given list of numbers
-- use of INFIX NOTATION ON FUNCTIONS with div
-- can be written: (div a b) or as (a `div` b)
-- e.g. average [4,76,3,45,18,31]

average ns = sum ns `div` length ns

-- using conditionals

doubleSmallNumber x = if x > 100
                        then x
                        else x*2

-- you can also use this form
-- this is because as a statement it can be written as one line

doubleSmallNumber' x = (if x > 100 then x else x*2) + 1

-- getting an element out of a list/string

"Steve Buscemi" !! 6
-- 'B'

-- adding a value to the beginning of a list

"A" : " SMALL CAT"
-- "A SMALL CAT"

-- list comprehensions for complex sets
-- e.g. S = {2*x|x in N| x ≤ 10}

[x*2 | x <- [1..10]]

-- e.g. all numbers from 50 to 100 whose remainder is 3 when divided by 7
[x | x <- [50..100], x `mod` 7 == 3]

-- e.g. adding function using tuples
add :: (Int, Int) -> Int
add (x,y) = x + y

-- e.g. zeroTo function
zeroTo :: Int -> [Int]
zeroTo n = [0..n]

-- e.g.
check :: [Int] -> Int -> Bool
check xs n = head xs == xs !! (n-1)

check2 :: [Int] -> Int -> Bool
check2 xs n  = if n ≤ length xs
               then head xs == xs!!(n-1)
               else False
