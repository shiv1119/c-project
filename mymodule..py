import smtplib
import getpass
import random

def send_email():
    smtp_object = smtplib.SMTP('smtp.gmail.com',587)
    smtp_object.ehlo()
    smtp_object.starttls()

    email = "shivnandan4132@gmail.com"
    password = "cmch zizu fqqi szxv"
    smtp_object.login(email,password)
    from_address = email
    subject = "From CODA"
    to_email = input()

    fixed_digits = 6 

    otp = str(random.randrange(111111, 999999, fixed_digits))

    msg = "Subject: " + subject + '\n Your otp to login registration system is ' + otp + '\n' + 'send with love from coda'

    smtp_object.sendmail(from_address,to_email,msg)
    otp_recieved = input("Enter otp recieved: ")
    if(otp == otp_recieved):
        print("Correct otp")
    else:
        print("Incorrect otp")
    
send_email()