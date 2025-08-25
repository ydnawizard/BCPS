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
through all the blocks in CBC and CFB. However, in OFB and Counter mode, only the first block changes. This is because while the first block of plaintext changed, the IV and key did not. The output of the encryption operation on the IV and key is would have to change in order to propogate a significant change throughout the ciphertext in these modes. As far as a statement for all block ciphers go, the effects of a bit flip are entirely dependent upon the mode.

# Problem 3
I tried pluigging multiple different bit combinations into the first block in my code and the first block of ciphertext for OFB and CFB were always the same. This is further confirmed to me by the fact that the first block is encrypted the same way in both modes. Therefore I will deduce that the two outputs with the same first block are either CFB or OFB. By this logic ECB is mode 3 and given the example in part 4 of the problem explanation, I can start working out what is what. The encryption of each block in ECB is independent of the ecnryptions of other blocks so even though 0101 is the last block in the example and the second block in mode 3, they should still be produced by the same input. Thus: 0101 -> 1000 and the input text given our logic this far is at least 1000 1000. Now, given that the ecnryption operation is the same for each mode, we can reference the output of the ECB example while plugging the mode 1 and mode 2 outputs into OFB and CFB to help us solve for the last block of plaintet. If we run the IV through OFB set each round equal to its corresponding block of ciphertext in mode 2, we get to to the third block where 0100 is plugged into the encryption operation. We can reference the ECB example and that 0100 gets ecnrypted to 0110. This means that we just need to solve x XOR 0110 = 1001, making the last block 1111. Mode 1 is CFB, mode 2 is OFB, and mode 3 is ECB.

![ofb](https://github.com/user-attachments/assets/2aec2ce0-443b-44f9-94a8-cad5bb417c24)

