Install android studio 
Install openSSL
Install burp
Generate Burp CA 
Add adb & emulator to the path 
Copy the CA to system as a root


# Steps:
1. Install Burp Suite-<https://portswigger.net/burp>

3. Export der certificate-go to settings-proxy-proxy setting-export der certificate. I exported it to C:\Githubciscopackettraceractivity\3rdcybersecuritybecode-burp_cert.der
4. convert der into pem-
- use this command:openssl x509 -inform DER -in burp_cert.der -out burp1_cert.pem
- either do it on kali or on windows-cmd prompt
- I tried on kali but not able to access shared folders(showing error). so, I removed kali and reinstalled it. But took the decision to do it on windows as it is much easier later
- go to cmd prompt. you have to install wsl for ubuntu installing on windows.
- command-   wsl --install
- once installed, go to the directory where certificate is: cd C:\Githubciscopackettraceractivity\3rdcybersecuritybecode: will see like this
- ![clipboard](https://i.imgur.com/MzJIREN.png)
- Here you write the command to change der into pem
- openssl x509 -inform DER -in burp_cert.der -out burp1_cert.pem
- check whether pem certificate is in right dir or not.
- done

7. Install Android Emulator and create AVD-
- download  Android emulator from <https://developer.android.com/studio>. It is giraffe. Will take quite some time to download
- once downloaded, go to virtual device manager or virtual device configuration-create device-system image and find pixel5/API 28
- download it. Again wait.
- you will get this once download is finished
- ![clipboard](https://i.imgur.com/gGuROh3.png)
- ![clipboard](https://i.imgur.com/9gVT6uX.png)
- ![clipboard](https://i.imgur.com/EdY4TUs.png)
- Its installed..if u click on play button..it will start-the emulator as shown below
- ![clipboard](https://i.imgur.com/07pkzT2.png)
- 


10. Install the certificate-(Ref:<https://blog.ropnop.com/configuring-burp-suite-with-android-nougat>)
11. 
- mitu@LAPTOP-FB9S7NQL:/$ cd mnt/c/Githubciscopackettraceractivity
/3rdcybersecuritybecode- go to this directory
- now you ahve to do hash old to tell generate hashcode and then append .0
- command- 
openssl x509 -inform PEM -subject_hash_old -in burp1_cert.pem |head -1

- ![clipboard](https://i.imgur.com/oek4Njz.png)- u wil get the hashcode-9a5ba575
- mv burp_cert1.pem <hash>.0- mv burp1_cert.pem 9a5ba575.0
- Now you have generated right pem file
# - Copy the certificate to the device We can use adb to copy the certificate over, but since it has to be copied to the /system filesystem, we have to remount it as writable. As root, this is easy with adb remount.

-so, first command is adb root: but didn't work for me. So, these are the steps which I followed:
a. mitu@LAPTOP-FB9S7NQL:/mnt/c/Githubciscopackettraceractivity/3rdcybersecuritybecode$ sudo apt update
[sudo] password for mitu:
 Result: Get:1 http://security.ubuntu.com/ubuntu jammy-security InRelease [110 kB]
Hit:2 http://archive.ubuntu.com/ubuntu jammy InRelease
Get:3 http://archive.ubuntu.com/ubuntu jammy-updates InRelease [119 kB]
Get:4 http://security.ubuntu.com/ubuntu jammy-security/main amd64 Packages [724 kB]
Get:5 http://security.ubuntu.com/ubuntu jammy-security/main Translation-en [160 kB]
Get:6 http://security.ubuntu.com/ubuntu jammy-security/main amd64 c-n-f Metadata [11.2 kB]
Get:7 http://security.ubuntu.com/ubuntu jammy-security/restricted amd64 Packages [771 kB]
Get:8 http://security.ubuntu.com/ubuntu jammy-security/restricted Translation-en [123 kB]
Get:9 http://archive.ubuntu.com/ubuntu jammy-backports InRelease [109 kB]
Get:10 http://security.ubuntu.com/ubuntu jammy-security/restricted amd64 c-n-f Metadata [536 B]

b. mitu@LAPTOP-FB9S7NQL:/mnt/c/Githubciscopackettraceractivity/3rdcybersecuritybecode$ sudo apt install adb

c. Check it : adb --version
Result: Android Debug Bridge version 1.0.41
Version 28.0.2-debian
Installed as /usr/lib/android-sdk/platform-tools/adb
d. I tried again- adb root..it started but it couldn't find emulator running though my emulator is on.
Error: * daemon not running; starting now at tcp:5037
* daemon started successfully
adb: unable to connect for root: no devices/emulators found* 
d. Next step: mount this dirctory:  cd /mnt/c/Users/nimes/AppData/Local/Android/Sdk/platform-tools
e. Add the path to system variable:  echo 'export PATH=$PATH:/mnt/c/Users/nimes/AppData/Local/Android/Sdk/emulator' >> ~/.bashrc
Result: source ~/.bashrc

f. Change the permission and mode:  chmod +x /mnt/c/Users/nimes/AppData/Local/Android/Sdk/emulator/emulator.exe

g. Now, it will list the devices if you put it in variable and then print it:
 avd_list=$(emulator.exe -list-avds)
 
 h.  echo "$avd_list"
 
 

```cmd
C:\Users\2no\AppData\Local\Android\Sdk\platform-tools-

- use the command on WSL prompt: cd /mnt/c/Users/nimes/AppData/Local/Android/Sdk/platform-tools
- 

C:\Users\2no\AppData\Local\Android\Sdk\emulator
```

List Android Studio - Virtual Device

```
➜ emulator.exe -list-avds
Pixel_3a_API_34_extension_level_7_x86_64
```

Run emulator with cmd 

```cmd
emulator.exe -avd Pixel_3a_API_34_extension_level_7_x86_64 --writable-system
```

Adb list devices 

```cmd
adb devices
```

Adb shell 

```cmd
adb shell
```

If you choose a device with the playstore enabled, you'll not be able to root. 
Switch to root. 

```
su
```

Then to go to the phone storage 

```
cd storage 
cd self 
cd primary 
```

To upload file to the phone 

```cmd
adb.exe push
```

Download 

```cmd
adb.exe pull
```

Convert the CA to PEM key

```
openssl x509 -inform DER -in cacert.der -out cacert.pem
openssl x509 -inform PEM -subject_hash_old -in cacert.pem |head -1 //on linux

notepad cacert.pem  // On windows first line is the hash

mv cacert.pem 9a5ba575.0
chmod 644 9a5ba575.0
```

To copy the certificat 

```cmd 
emulator.exe -avd Pixel_3a_API_34_extension_level_7_x86_64 -writable-system
```

```
adb root
adb remount
adb push ./<hash.O> /sdcard/
adb shell
# mv ~/<hash.O> /system/etc/security/cacerts
```


Acces WSL file fro windows 

```
\\wsl$
```


[Aurora Store](https://f-droid.org/repo/com.aurora.store_47.apk) 

[Get APK](https://apkpure.com/fr/)  not legit be carefull ...