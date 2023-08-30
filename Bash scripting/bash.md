Exercises


I - prompt user
Write a shell script prompting the user for his name, then replying Hello <name>.


Steps:

1. Open Kali
2. I made a folder called bash in home dir
3. cd bash
4. sudo nano bash1
5. ![clipboard](https://i.imgur.com/PetApxj.png)
6. Save it
7. Go back to Kali terminal
8. type: ./bash1
9. It will give the error file execution not permitted
10. type: sudo chmod +x bash1
11. now type: ./bash1
12. output: ![clipboard](https://i.imgur.com/u5HXnns.png)


II - ***receive arguments
Write a shell script receiving a name as argument, then replying Hello <name>.***

1. Create a new file in bash folder called bash2: sudo nano bash2
2. Write the following code:
![clipboard](https://i.imgur.com/WrA2x7f.png)
3. Save and exit
4. on terminal type: ./bash2 Mitu Shah
5. Output:![clipboard](https://i.imgur.com/jEXY2G2.png)
6. See the differnce in both lines
7
 

III - ***path to
Write a shell script receiving a path as argument, depending on if it's a file or a directory, display or list its content.***

You can complexify the script by only displaying file containing text (ex: .txt, .js) and returning an error for anything else (ex: .mp3, .pdf).

Answer:
for this I have started working in VSCodium( because I cannot copy anything from kali to host machine windows). So, I went to C:\Githubciscopackettraceractivity\3rdcybersecuritybecode\Bash scripting folder and made bash3.md

$# is used to check if the number of arguments passed to the script is equal to zero, which would mean that no arguments were provided. If $# is zero, it implies that the script was invoked without any arguments, and the script provides a usage message and exits with a non-zero status to indicate an error.


IV - information
Write a shell script to see the current date, time, username, and directory.

Points to note: 1. Bash is case sensitive. so date syntax is $(date+"%Y-%m-%d")
                2. Similarly for time.
                3. You get date and time both from date command

V - list of groups
Write a shell script checking all the groups a user is part of and for each one display <username> is part of the group <group>.



# WEB SCRAPING( Ref: https://www.youtube.com/watch?v=mtDoQDp0nj8)

****After learning how to use the curl command to get a page's HTML. You should write a script to get all the laptops from this webshop page and print each one of them on a line in your terminal.****

1. Use of curl command:
- I have chosen web page of amazon.com.be and searched for HP laptop.
- Once I get the page, right click on to it  and go to inspect page.
- Then click on network and find the first link with GET method. Its generally the first link, but you can try other links too.
- right click on the link and copy as curl(bash).
- Now go to the terminal. I used VSCodium, Git bash terminal.Path: C:\Githubciscopackettraceractivity\3rdcybersecuritybecode\Bash scripting
- Paste the curl link. It will be a big link, we can remove some of it.
- It was this link: curl 'https://www.amazon.com.be/s?crid=J5K1X4I1IO0W&i=aps&k=hp%20laptop&ref=nb_sb_noss_1&sprefix=hp%20laptop%2Caps%2C392&url=search-alias%3Daps'   -H 'authority: www.amazon.com.be'   -H 'accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.7'   -H 'accept-language: en-US,en;q=0.9,de;q=0.8,fr;q=0.7'   -H 'cookie: session-id=261-1607759-5361250; ubid-acbbe=262-7577084-9892524; lc-acbbe=en_GB; x-acbbe="6QF979jTqQbfdbngE@DAfobhmnrvP@He"; at-acbbe=Atza|IwEBIGViWMexf28YPKQCGT5SxumEnRCiy_0PErermqiLmNmsP5jsUBbvzluQs90tn1kFCm32ZnWVkDlYr4N1N2K0wgo01gdcmRmOo-PgvGc-CFGH0dhZlpR_MVrs4I5rakW3Bb1FyGrmNB0VeyWyA-l1958PN5lif0c4LCLNsOb0SN6piGrAUj2VK5Tdx1FTSX8pMeMpSwC3_QPdGJzh5kKIyCaYtKbaEcol4BxcUfFvuGlHYw; sess-at-acbbe="vQLPCaXoVq8arvWYhQ4WKgNQkmsCvc5D/08YoMqbzkw="; sst-acbbe=Sst1|PQG6RkAFv_X9H8iqXwMCMIo_CQKLBXG_L6asQxKZwUvtDzCJOghyCPaApIRGo8k1z-Q6EvGwGnuZVxcnsoqbeZa6rNLRcEtd57c5nrC7Ldb-O-0U6JqIRMe1-ltJo1atDnJP6D6ItRnIRNA3_90MVwoZCVJohMqbyQkHGo7Hy9brrX-4CH2A1ONOqp9DJ8cdnBCLwalwO8X9rii6NiOCoH10MzsjAgAGLlot3OvkYUcs_bXzFw156EM9OVB2VWTAmuKfiXuLBCONqsRR7mI3dQyBkqfZs6_G3MISKjs-JFDAXDw; i18n-prefs=EUR; s_nr=1677164646848-New; s_vnum=2109164646849%26vn%3D1; s_dslv=1677164646850; csd-key=eyJ3YXNtVGVzdGVkIjp0cnVlLCJ3YXNtQ29tcGF0aWJsZSI6dHJ1ZSwid2ViQ3J5cHRvVGVzdGVkIjpmYWxzZSwidiI6MSwia2lkIjoiMWM3NmZmIiwia2V5IjoiT3ZETG1nUWltYndKdzFBY0hOWXNMc2N2c3pnc05RTi9PWEY1eDZOcSs4NUMrTmFMY0YwVlRuejErZVBzUlkxZVh4ZHF0cCt4T2V6QmVZQ2g1OVNPcTB2NTl3OWttVGtCSWxsZDNVWlNTRTdySEx6L282eVp5WXlUcE53MFFzOTdMRFZwVTlqbThma3Z1Ty8wcWEvSUZ4VWNkbG1VSnBHdy8wTERIZWhCQ014bGxNTGJpNmI2Q3N3bGdscUZPalhZN3pnL1kxY1ExTFY0MUxzVXdwVEVUOFRRL1FBcERNRElSUThvb0xKcUJCZHMwUktxbStGMzYyNzBFc3IrRG1mRzlBSGFZbG5yRVBPb1hRbWpkUWVaL1dHRlNJeTZUYnBrWVA0QW1KTHd5eWhpOExnbTNaRytjcnl5MDVKQmxoVkg3aHFmTG5uSFJKOVJJdzJBSGhrSTVnPT0ifQ==; session-id-time=2082787201l; session-token=lHYYP7BPmjpHBLsLeNOoPN+bAa46XIEK2JOx6vMpI6m8rv+RwMLHFXxWsUYJvtf7nGIO44QmT7VwrIZShbP+aWd0SXyXjhdX/rw+zr0t1/8DoiNghs+ZATV3X2jDJdrIyrJ0Y4M5opYrcfSq1dctzTHL36/n2yANiQ6LTz6rZqE0FjbsVP1w3nZf43DR+E/+xKH8UCwOZhr7P06BhGo5juBFOH3/529JkpYyi8zWr8rSyZZoocbOUTC6MCNDdPXoqkJ8tiGFg8VjMGeh/GLii8WtPAl+GYaDaGKz3lr13IZrQ9NQKE5XruWmxcHQ3MhG7IhKpU6xa0KQiM2qTfWgaSfrAG4aMLpSvuZUqHK2HYE5zJQ6MVdZUjpusQnXc81AMyWVHJQGM3U=; csm-hit=tb:VP7162ZM3XY9B231VEZH+s-RTK41NSTJCQRYEP4KQTG|1693337615199&t:1693337615199&adb:adblk_no'   -H 'downlink: 10'   -H 'ect: 4g'   -H 'referer: https://www.amazon.com.be/s?k=hp+laptop&crid=1E69YN0WWQ9BG&sprefix=hp+laptop%2Caps%2C161&ref=nb_sb_noss_1'   -H 'rtt: 200'   -H 'sec-ch-ua: "Chromium";v="116", "Not)A;Brand";v="24", "Google Chrome";v="116"'   -H 'sec-ch-ua-mobile: ?0'   -H 'sec-ch-ua-platform: "Windows"'   -H 'sec-ch-ua-platform-version: "15.0.0"'   -H 'sec-fetch-dest: document'   -H 'sec-fetch-mode: navigate'   -H 'sec-fetch-site: same-origin'   -H 'sec-fetch-user: ?1'   -H 'upgrade-insecure-requests: 1'   -H 'user-agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/116.0.0.0 Safari/537.36'   --compressed

- Don't be intimitated by this. We can remove most of its part. What is important is: user agent and link itself. That's it.
- so, final link- curl 'https://www.amazon.com.be/s?crid=J5K1X4I1IO0W&i=aps&k=hp%20laptop&ref=nb_sb_noss_1&sprefix=hp%20laptop%2Caps%2C392&url=search-alias%3Daps' \ -H 'user-agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/116.0.0.0 Safari/537.36' which is pretty good.
- Now to check whether, we are getting the same web page as expected. we will store the output in a temporary file as shown: curl 'https://www.amazon.com.be/s?crid=J5K1X4I1IO0W&i=aps&k=hp%20laptop&ref=nb_sb_noss_1&sprefix=hp%20laptop%2Caps%2C392&url=search-alias%3Daps' \ -H 'user-agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/116.0.0.0 Safari/537.36'>>temp13.html  
- now go to windows explorer and click on temp13.html. It should give you the laptop web page of Amazon.
- First and important step is done.

2. Now you have to make bash file and use a variable to store the output of curl command. We don't need temporary file any more.
3. Since we need the names of laptops and its prices, select that part from the webpage individually and right click on it and select inspect.
4. It will give you a span tag with a class. 
 ![clipboard](https://i.imgur.com/XxYxKCq.png)
 
7. Copy it and use sed command to parse it and get only the name of laptops.Put it in a array and iterate it through to get the required result.
8. Repeat for the price.
9. End



