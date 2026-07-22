Before solving this problem, let's first understand two terms:

Winning state: For the current player, if there exists a move that leaves the opponent in a losing state, then the current state is a winning state. That is, the current player can move to a losing state.

Losing state: For the current player, if every possible move leaves the opponent in a winning state, then the current state is a losing state. That is, the current player cannot move to any losing state.

Conclusion

Suppose there are n piles of stones, with sizes a1,a2,…,ana1;
​
If a1 ^ a2^ ... ^ an ≠ 0
then the first player wins; otherwise, the first player loses.

Proof

At the end of game, every pile has 0 stones, and
 0 ^ 0 ^ 0...^ 0 = 0;

 During a move:
1. if a1 ^ a2 ^ ... ^ an = x != 0.
 Then, the current player can always remove some stones from onre pile to make the XOR result become 0;

 Proof : Let the highest set bit of x be the k-th bit.
 then among a1, a2 .. an, there must exist some ai, whose k-th bit is 1, and moreover ai ^ x < ai. 
 Now, remove (ai - (ai ^ x)) stones from the i-th pile.
 The remaining stones in that pile will be:
        ai - (ai - (ai ^ x)) = ai ^ x;

Then the new XOR sum becomes:
  a1 ^ a2 ^ . ^ ai ^ x .. ^ an = x ^ x = 0;


2. if a1 ^ a2 ^ ... ^ an = 0;
  then no matter how the current player moves, the resulting XOR sum will necessarily be non-zero.

  Proof by contradiction: Suppose the player removes some stones from the i-th pile, leaving a′stones where 0 ≤ a′< ai (since at least one stone must be removed), and suppose the new XOR sum is still 0:
    a1 ^ a2 ^.... ^ ai ... ^ an = 0;

  XOR the original equation with the new one:
    (a1 ^ a2 ^.... ^ ai ... ^ an) ^ (a1 ^ a2 ^.... ^ ai′ ... ^ an) = ai ^ ai′ = 0;
  This implies ai=a′, which contradicts 0 ≤ ai′ < ai. Therefore, the new XOR sum cannot be 0.

  Based on the above three proofs:
  1. If the first player faces a position where a1 ^ a2 ^ ... ^ an != 0.
  then the first player can always make a move to turn the position into one where the XOR sum is 0. Repeating this process, the opponent will eventually face the terminal position with no stones left. Hence, the first player wins.

  2. If the first player faces a position where a1 ^ a2 ^ ... ^ an = 0.
then no matter how the first player moves, the resulting XOR sum will be non-zero. Then the second player can always move to restore the XOR sum to 0. Repeating this, the first player will eventually face the terminal position with no stones left. Hence, the first player loses.