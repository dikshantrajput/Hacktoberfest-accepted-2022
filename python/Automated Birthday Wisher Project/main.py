##################### Extra Hard Starting Project ######################

# 1. Update the birthdays.csv

# 2. Check if today matches a birthday in the birthdays.csv

# 3. If step 2 is true, pick a random letter from letter templates and replace the [NAME] with the person's actual name from birthdays.csv

# 4. Send the letter generated in step 3 to that person's email address.

import datetime as dt
from random import randint
import pandas
import smtplib

final_letter_list = []

now = dt.datetime.now()
month = now.month
day = now.day

data = pandas.read_csv("birthdays.csv")
birthday_row = (data[data.day == day])
birthday_row_dict = birthday_row.to_dict()
birthday_boy = birthday_row_dict["name"][0]
birthday_boy_email = birthday_row_dict["email"][0]


if month == int(data.month) and day == int(data.day):
    random_letter = randint(1, 3)
    with open(f"letter_templates/letter_{random_letter}.txt", "r") as file:
        letter_data = file.readlines()
        final_letter_list.append(letter_data[0].replace("[NAME]", f"{birthday_boy}"))
        for lines in letter_data[1:]:
            final_letter_list.append(lines)

        final_letter = "".join(final_letter_list)

#sending a brithday email

MY_EMAIL = "karanmandve1@gmail.com"
PASSWORD = "9545721980"

with smtplib.SMTP("smtp.gmail.com") as connection:
    connection.starttls()
    connection.login(user=MY_EMAIL, password=PASSWORD)
    connection.sendmail(from_addr=MY_EMAIL,
                        to_addrs=birthday_boy_email,
                        msg=f"Subject:Birthday Mail\n\n{final_letter}"
                        )


