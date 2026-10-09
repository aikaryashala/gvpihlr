# SMS Templates — Question Bank

Answer everything **on paper**. Remember the golden rule: the words that are the same for every customer live inside quotes; the pieces that change are variables. Cut exactly at the boundary — punctuation, spaces, `Rs.`, and labels stay inside the strings. Name every variable by what its value **means**, joining words with a capital at each word (`BillAmount`).

Your variable names may differ from the answer key's — that is fine, as long as they clearly say what the value means. The **strings must match exactly**.

Write your answers in your notebook. Answers are **not** in this file.

---

# Part A — Spot What Varies

Do **not** write the print statement yet. Just list the varying pieces and give each one a good variable name.

**A1.** Two customers received these:

```sms
Dear Ravi, your parcel will arrive on 18-Jul-25.
```

```sms
Dear Sita, your parcel will arrive on 21-Jul-25.
```

**A2.**

```sms
Flat 40% off at Trends, Ameerpet till Sunday! Show this SMS at billing.
```

---

# Part B — Write the Print Statement

Write the print statement that generated each SMS.

**B1.**

```sms
Your Swiggy order 8821 will arrive in 25 mins.
```

**B2.**

```sms
A/c XX8907 debited by Rs.720 on 15-Jul-25. Avl bal: Rs.9280.
```

**B3.**

```sms
Dear Lakshmi, your appointment is confirmed for 18-Jul-25 at 10:30AM. Token No: 14.
```

**B4.** Now the other direction — the program and its values are given. Write the exact SMS the customer receives:

```
CustomerName = "Kiran"
BillMonth = "June"
BillAmount = 1240
DueDate = "25-Jul-25"
print "Dear " + CustomerName + ", your electricity bill for " + BillMonth + " is Rs." + BillAmount + ". Pay by " + DueDate + " to avoid late fee."
```

---

# Part C — The Big Tickets

Dense, real-style ticket messages. Walk left to right, cut at every varying piece, and watch for values used more than once.

**C1.** A train ticket:

```sms
PNR:4528167390,TRN:12723,DOJ:22-Mar-25,SC-TPTY,VINODKUMAR,S6-34,FARE:970,DEP:07:15.Happy Journey-IRCTC
```

**C2.** A movie ticket:

```sms
Booking ID:MV88123,KGF Chapter 2,PVR Kukatpally,Screen 4,Seats:D12,D13,20-Apr-25 06:30PM.Total Rs.560.Enjoy the movie!
```

---

# Part D — More Messages

Same job, two more messages. Watch especially whether two values of the same *kind* get two different *names*.

**D1.** A bank transfer:

```sms
Rs.15000 transferred from A/c XX3401 to A/c XX8266 on 16-Jul-25. Ref No 517209884321. Avl bal: Rs.16450.
```

**D2.** A train delay:

```sms
Train 12727 GODAVARI EXP from Hyderabad to Visakhapatnam is delayed by 40 mins. Expected departure 07:25 from platform 6.
```

---

When you finish, check yourself against the answer key. Your names may differ from ours; your **strings** must not — compare every space, comma, colon, and full stop.
