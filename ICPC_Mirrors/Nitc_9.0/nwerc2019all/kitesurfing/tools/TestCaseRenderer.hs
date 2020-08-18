{-# LANGUAGE FlexibleContexts          #-}
{-# LANGUAGE LambdaCase                #-}
{-# LANGUAGE NoMonomorphismRestriction #-}
{-# LANGUAGE RecordWildCards           #-}
{-# LANGUAGE TypeFamilies              #-}
import Control.Monad
import Diagrams.Backend.SVG.CmdLine
import Diagrams.Prelude hiding (distance)

-- Colours:

waterCol :: Colour Double
waterCol = dodgerblue

sandCol :: Colour Double
sandCol = sandybrown

trajectoryCol :: Colour Double
trajectoryCol = black

rulerCol :: Colour Double
rulerCol = black

-- Draw a checkered flag:

waving :: Deformation V2 V2 Double
waving = Deformation $ p2 . (\(x,y) -> (x, y + 0.3 * cos x)) . unp2

grid :: Path V2 Double
grid = vcat [ hcat [ tile (even $ i+j) | j <- [0..5] ] | i <- [0..3] ]
  where
    tile b = mconcat $ replicate (if b then 1 else 2) (square 1)

flag :: Diagram B
flag = [pole, cloth] # (hcat # composeAligned alignT) # lwL 0.05
  where
    cloth = grid # deform' 0.0001 waving # strokeP # fillRule EvenOdd # fc black
    pole = rect 0.4 10 # fc brown

-- Draw the water surface:

water :: Double -> Diagram B
water len = zigzag # glueLine # strokeLoop
                   # scaleUToX len
                   # fc waterCol # lc waterCol # lwL 0.02
  where
    zigzag =    cubicSpline False (map p2 [(k,0.2 * (-1)**k) | k <- [0..10*len]])
             <> fromOffsets (map r2 [(0,-2),(-10*len,0),(0,2)])

-- Draw an island:

island :: Double -> Diagram B
island len | len <= 0.4  = ellipseXY len 0.33 # scale 0.5 # alignL # translateY 0.035 # fc sandCol # lw none
island len =
  (arcBetween a b 0.2 <> arcBetween b a 0.13)
    # closeLine # strokeLoop
    # fc sandCol # lw none
  where
    [a,b] = map p2 [(0,0),(len,0)]

-- Data types to store a test case and its solution:

data Move = Surf Double | Jump Double
  deriving Show

data TestCase = TestCase { distance :: Double
                         , jumpLength :: Double
                         , jumpCost :: Double
                         , islands  :: [(Double,Double)]
                         , moves :: [Move]
                         , scaleFactor :: Double
                         } deriving Show

-- Draw the trajectory made up of surf and jump segments of given lengths:

trajectory :: TestCase -> Diagram B
trajectory TestCase{..} =
       path # strokeLine # dashingL [0.08,0.08] 0 # lc trajectoryCol # lwL 0.03
    <> circle 0.05 # fc trajectoryCol
    <> circle 0.05 # fc trajectoryCol # translateX distance
  where
    nodes = [(x,-x^2) | x <- [-1,-0.75..1]]
    segment (Surf len) = fromOffsets $ map r2 [(len,0)]
    segment (Jump len) = cubicSpline False $ scaleToX len $ map p2 nodes
    path = mconcat $ map segment moves

-- Draw markings with equal spacing to indicate distances:

markPositions :: Int -> [(Int,Bool)]
markPositions n
  | n <= 30 && n`mod`3 == 0  = [(i,i`mod`3 == 0) | i <- [0..n]]
-- | n <= 30                  = [(i,i`mod`5 == 0) | i <- [0..n]]
  | otherwise                = [(x,isBig x) | x <- [0,step..(n-1)] ++ [n]]
  where
    step = head $ dropWhile (\x -> 30*x < n) $ iterate (*10) 1
    isBig x = x == n || (x`div`step) `mod` 5 == 0

ruler :: TestCase -> Diagram B
ruler TestCase{..} =
  mconcat [ mconcat marks
          , fromOffsets [r2 (distance,0)]
          ] # lc rulerCol # lw thin
  where
    mark isBig x
      | isBig      = mconcat [ fromOffsets [r2 (0,0.15)] # centerY
                             , text (show x) # font "monospace" # scale 0.24 # translateY (-0.25)
                             ]
      | otherwise  = fromOffsets [r2 (0,0.08)] # centerY
    
    positions = markPositions (round $ distance/scaleFactor)
    marks = map (\(x,isBig) -> mark isBig x # translateX (fromIntegral x * scaleFactor)) positions
    rects = mconcat marks

-- Draw a sample case and its solution:

renderSample :: TestCase -> Diagram B
renderSample tc@TestCase{..} =
  mconcat [ trajectory tc
          , mconcat [island (b-a) # translateX a | (a,b) <- islands]
          , flag # scale 0.07 # alignB # translateX distance
          , water (distance+0.5) # translate (r2 (-0.25,0.035))
          , ruler tc # translateY (-0.5)
          ]

-- Draw a secret case and its solution:

renderSecret :: TestCase -> Diagram B
renderSecret tc@TestCase{..} =
  mconcat [ renderSample tc
          , topLeftText ("D=" ++ show (round jumpLength) ++ ", T=" ++ show (round jumpCost))
                 # font "monospace" # scale 0.3 # translateY 1.2
          ]

-- Draw a case without ruler and flag:

renderPartial :: TestCase -> Diagram B
renderPartial tc@TestCase{..} =
  mconcat [ trajectory tc
          , mconcat [island (b-a) # translateX a | (a,b) <- islands]
          , water (distance+0.5) # translate (r2 (-0.25,0.035))
          ]

-- Draw the sample illustration for the problem statement:

sample1 :: TestCase
sample1 = TestCase { distance = 9
                   , jumpLength = 3
                   , jumpCost = 4
                   , islands = [(2,4),(7,8)]
                   , moves = [Surf 1.7, Jump 3, Surf 1.3, Jump 3]
                   , scaleFactor = 1
                   }

sample2 :: TestCase
sample2 = TestCase { distance = 12
                   , jumpLength = 5
                   , jumpCost = 3
                   , islands = [(1,3),(5,7),(8,11)]
                   , moves = [Jump 3.4, Jump 4.6, Jump 4]
                   , scaleFactor = 1
                   }

samples :: Diagram B
samples = map (centerX . renderSample) [sample1,sample2] # vsep 1

-- Draw the illustrations for the solution slides:

slide1 :: Diagram B
slide1 = renderSample sample1 # frame 0.3

slide2a :: Diagram B
slide2a =
    [ renderPartial tc1 <> arrowBetween (3 ^& 0.8) (2.4 ^& 0.8)
    , renderPartial tc2
    ] # hsep 1 # frame 0.3
  where
    tc1 = TestCase 5 0 0 [(1.5,2.2),(2.7,4)] [Surf 1, Jump 3.5, Surf 0.5] 1
    tc2 = TestCase 5 0 0 [(1.5,2.2),(2.7,4)] [Surf 0.5, Jump 3.5, Surf 1] 1

slide2b :: Diagram B
slide2b =
    [ renderPartial tc1
    , renderPartial tc2
    , renderPartial tc3
    ] # hsep 0.6 # frame 0.3
  where
    tc1 = TestCase 6 0 0 [] [Jump 2.2, Jump 2.2, Jump 1.6] 1
    tc2 = TestCase 6 0 0 [] [Jump 2.2, Jump 2.2, Surf 1.6] 1
    tc3 = TestCase 6 0 0 [] [Surf 6] 1

slide3a :: Diagram B
slide3a =
  mconcat [ circle 0.05 # translateX 8 # fc trajectoryCol
          , renderPartial tc
          ] # frame 0.3
  where
    tc = TestCase 14 0 0 [(9,10),(12,14)] [Jump 6, Surf 2, Jump 6] 1

slide3b :: Diagram B
slide3b = renderPartial tc # frame 0.3
  where
    tc = TestCase 14 0 0 [(10,13)] [Jump 4, Jump 4, Jump 2, Jump 4] 1

-- Read a case and its solution from stdin:

rescale :: TestCase -> TestCase
rescale tc@TestCase{..} =
    tc { distance = k*distance
       , islands = map (\(x,y) -> (k*x,k*y)) islands
       , moves = map (\case Jump x -> Jump (k*x); Surf x -> Surf (k*x)) moves
       }
  where
    k = scaleFactor

parseTestCase :: IO TestCase
parseTestCase = do
  [distance,jumpLength,jumpCost] <- map read . words <$> getLine

  n <- read <$> getLine
  islands <- replicateM n $ do
    [x,y] <- map read . words <$> getLine
    return (x,y)
  
  m <- read <$> getLine
  moves <- replicateM m $ do
    [act,len] <- words <$> getLine
    return $ (if act == "jump" then Jump else Surf) (read len)
  
  let scaleFactor = min 1 (18/distance)
  return $ rescale TestCase{..}


main :: IO ()
main = mainWith (frame 0.3 . renderSecret <$> parseTestCase)
