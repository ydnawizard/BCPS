# BCPS

# Problem 1:
Compile and Run main.c

# Problem 2
Non Corrupted Output: \
<img width="451" height="347" alt="20250713_16h04m41s_grim" src="https://github.com/user-attachments/assets/c96d6163-3b3b-4c0f-b576-77d264042dc5" />
\
Corrupted Output (Flipped first bit of plaintext in first block):\
<img width="476" height="350" alt="20250713_16h06m22s_grim" src="https://github.com/user-attachments/assets/9c14f22f-0341-442a-96df-e0cee798c94c" />
\
Altering one bit seems to have different effects depending on the mode. The change seems to propogate
through all the blocks in CBC and CFB. However, in OFB and Counter mode, only the first block changes. This is because while the first block of plaintext changed, the IV and key did not. The output of the encryption operation on the IV and key is would have to change in order to propogate a significant change throughout the ciphertext in these modes. \

# Problem 3
I tried pluigging multiple different bit combinations into the first block in my code and the first block of ciphertext for OFB and CFB were always the same. This is further confirmed to me by the fact that the first block is encrypted the same way in both modes. Therefore I will deduce that the two outputs with the same first block are either CFB or OFB. By this logic ECB is mode 3 and given the example in part 4 of the problem explanation, I can start working out what is what. The encryption of each block in ECB is independent of the ecnryptions of other blocks so even though 0101 is the last block in the example and the second block in mode 3, they should still be produced by the same input. Thus: 0101 -> 1000 and the input text given our logic this far is at least 1000 1000. Further, given that in ECB e(1000) = 0101 and e^-1(0101) = 1000, it also follows that e(0101) = 1000 and e^-1(1000) = 0101. So our plaintext is 1000 1000 0101. Im not sure how to discern which one is CFB and which one is OFB. Im going to guess mode 1 is OFB because I see the IV in the output and mode 2 is CFB.
