# Vigenere-Cryptanalysis
This was a university group project for Computer Security, implenting encryption, decryption, and cryptanalysis with the Vigenere Cipher.
There is a twist on the cipher in that alongside the letters a-z, the symbols *, = and + are also a part of the alphabet.

Do not copy code from here to complete assignments or projects. Looking is fine, but please do your own work.

# Running the Code
Clone the repository into your preferred development environment. We used Visual Studio, so that's what the next steps will cover.
Open the .sln file. From here, the local windows debugger can be run for program execution. The program will always prompt for a text filename first.

# Verifying Encryption
Type in your desired text file, and follow the prompts for encryption. Enter a 3-5 letter key, and your ciphertext will be recorded in output.txt

# Verifying Decryption
output.txt can be used here since it contains the ciphertext immediately after an encryption operation.
Specify it for the file, follow the prompts for decryption, and enter the key used in a previous step.
Check output.txt against the original plaintext for correctness.

# Cryptanalysis
Unfortunately, the complete list of project requirements cannot be found, but the cryptanalysis can still be verified.
The cryptanalysis is based around using the frequencies for each letter in the language to form the key letter by letter.
salad.txt is the target file here. Specify it, and follow the prompts for cryptanalytic decryption.
The cryptanalysis derived key will be an English word enclosed by *
