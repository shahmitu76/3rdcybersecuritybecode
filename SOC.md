# SOC

## Pyramid of pain

1. Hash values: You may also encounter so-called fuzzy hashes, which attempt to solve this problem by computing hash values that take into account similarities in the input.  In other words, two files with only minor or moderate differences would have fuzzy hash values that are substantially similar, allowing an investigator to note a possible relationship between them.  Ssdeep is an example of a tool commonly used to compute fuzzy hashes.  Even though these are still hash values, they probably fit better at the "Tools" level of the Pyramid than here, because they are more resistant to change and manipulation.  In fact, the most common use for them in DFIR is to identify variants of known tools or malware, in an attempt to try to rectify 
2. <https://detect-respond.blogspot.com/2013/03/the-pyramid-of-pain.html>- very interesting--read it

Tryhackme:

<https://tryhackme.com/room/mitre>



Answer the questions below
Besides Blue teamers, who else will use the ATT&CK Matrix? (Red Teamers, Purpe Teamers, SOC Managers?)
Red Teamers
What is the ID for this technique?

T1566
Based on this technique, what mitigation covers identifying social engineering techniques?

User Training
What are the data sources for Detection? (format: source1,source2,source3 with no spaces after commas)

Application log,file,Network traffic
What groups have used spear-phishing in their campaigns? (format: group1,group2)

Axiom, gold southfield
Based on the information for the first group, what are their associated groups?

group 72
What software is associated with this group that lists phishing as a technique?

hikit
What is the description for this software?

Hikit is malware that has been used by Axiom for late-stage persistence and exfiltration after the initial compromise
This group overlaps (slightly) with which other group?

winnti group
How many techniques are attributed to this group?

15



Task5:

reference: <https://medium.com/@haircutfish/tryhackme-mitre-room-task-4-car-knowledge-base-task-5-mitre-engage-5d0573fbccbc>(very nicely explained)

### Answer the questions below
Under Prepare, what is ID SAC0002?
PERSONA CREATION
What is the name of the resource to aid you with the engagement activity from the previous question?

persona profile worksheet
Which engagement activity baits a specific response from the adversary?

lures
What is the definition of Threat Model?

A risk assessment that models organizational strengths and weaknesses 

<https://tryhackme.com/room/mitre> (continued)

# task6:


reference: <https://medium.com/@haircutfish/tryhackme-mitre-room-task-6-mitre-d3fend-task-7-att-ck-emulation-plans-924969058c84>

task 8:

reference:
<https://medium.com/@haircutfish/tryhackme-mitre-room-task-8-att-ck-and-threat-intelligence-task-9-conclusion-7314d008f6d5>
Answer the questions below
What is a group that targets your sector who has been in operation since at least 2013?
apt33
As your organization is migrating to the cloud, is there anything attributed to this APT group that you should focus on? If so, what is it?

cloud accounts
What tool is associated with the technique from the previous question?

ruler
Referring to the technique from question 2, what mitigation method suggests using SMS messages as an alternative for its implementation?

multifactor authentication
What platforms does the technique from question #2 affect?

Azure AD, Google Workspace, IaaS, Office 365, SaaS





