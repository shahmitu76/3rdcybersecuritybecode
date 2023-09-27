
1. Install Docker(Done previously ..in DVWA)

2. Run docker pull bkimminich/juice-shop- problem encountered- in kali, network was not working.. i changed to NAT..then it was fine.

3. Run docker run --rm -p 3000:3000 bkimminich/juice-shop

After running docker:

![clipboard](https://i.imgur.com/YMu31vo.png)



4. Browse to http://localhost:3000 (on macOS and Windows browse to http://192.168.99.100:3000 if you are using docker-machine instead of the native docker installation)

Docker commands
To run the docker container: docker run --rm -p 3000:3000 bkimminich/juice-shop

To list the docker containers: docker ps

To restart a running container: docker restart -t 0 CONTAINER_ID

To stop a running container: docker stop -t 0 CONTAINER_ID

To start a stopped container: docker start -a -i CONTAINER_ID

OWASP Juice Shop is probably the most modern and sophisticated insecure web application! It can be used in security trainings, awareness demos, CTFs and as a guinea pig for security tools! Juice Shop encompasses vulnerabilities from the entire OWASP Top Ten along with many other security flaws found in real-world applications!

Description
Juice Shop is written in Node.js, Express and Angular. It was the first application written entirely in JavaScript listed in the OWASP VWA Directory.

The application contains a vast number of hacking challenges of varying difficulty where the user is supposed to exploit the underlying vulnerabilities. The hacking progress is tracked on a score board. Finding this score board is actually one of the (easy) challenges!

Apart from the hacker and awareness training use case, pentesting proxies or security scanners can use Juice Shop as a “guinea pig”-application to check how well their tools cope with JavaScript-heavy application frontends and REST APIs.

Translating “dump” or “useless outfit” into German yields “Saftladen” which can be reverse-translated word by word into “juice shop”. Hence the project name. That the initials “JS” match with those of “JavaScript” was purely coincidental!

Step by Step
https://www.youtube.com/watch?v=0YSNRz0NRt8&list=PL8j1j35M7wtKXpTBE6V1RlN_pBZ4StKZw

https://help.owasp-juice.shop/appendix/solutions.html

https://curiositykillscolby.com/