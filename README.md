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
through all the blocks in CBC and CFB. However, in OFB and Counter mode, only the first block changes. This is because while the first block of plaintext changed, the IV and key did not. The output of the encryption operation on the IV and key is would have to change in order to propogate a significant change throughout the ciphertext in these modes.
