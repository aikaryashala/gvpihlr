# SMS Templates — Answers with Reasoning

Check the **reasoning**, not just the line. Variable names may differ from yours — that is fine if they say what the value means. The strings must match **exactly**: every space, comma, colon, and full stop.

---

# Part A — Spot What Varies

**A1.** Two pieces vary: the customer's name (`Ravi` / `Sita`) and the arrival date (`18-Jul-25` / `21-Jul-25`).

Names: `CustomerName`, `ArrivalDate`. Everything else — including `Dear ` and the final `.` — is identical in both copies, so it is fixed template text.

**A2.** Three pieces vary: `40` (`DiscountPercent`), `Ameerpet` (`BranchName`), `Sunday` (`LastDay`). The `%` sign stays in the string — for every customer the offer is *some* percent, so the sign is fixed and only the number varies. `Trends` is fixed (the store sends its own offers).

---

# Part B — Write the Print Statement

**B1.** `print "Your Swiggy order " + OrderNo + " will arrive in " + MinutesToArrive + " mins."`

`Swiggy` is fixed — Swiggy sends its own messages. The strings carry the spaces on both sides of each variable.

**B2.** `print "A/c " + AccountNo + " debited by Rs." + DebitAmount + " on " + Date + ". Avl bal: Rs." + Balance + "."`

Four variables. `Rs.` stays in the string both times, and `". Avl bal: Rs."` — full stop, space, label, and `Rs.` — is one fixed string between the two amounts.

**B3.** `print "Dear " + PatientName + ", your appointment is confirmed for " + AppointmentDate + " at " + AppointmentTime + ". Token No: " + TokenNo + "."`

Four variables. `". Token No: "` is one fixed string — full stop, space, label, colon, space — and the final `"."` closes the sentence after the token number.

**B4.**

```sms
Dear Kiran, your electricity bill for June is Rs.1240. Pay by 25-Jul-25 to avoid late fee.
```

The reverse direction: replace each variable with its value and glue. Check the boundaries you have been writing all sheet: `Rs.` glued straight onto `1240`, space after the full stop carried by `". Pay by "`.

---

# Part C — The Big Tickets

**C1.**

```
print "PNR:" + PnrNo + ",TRN:" + TrainNo + ",DOJ:" + JourneyDate + "," + FromStation + "-" + ToStation + "," + PassengerName + "," + SeatNo + ",FARE:" + Fare + ",DEP:" + DepartureTime + ".Happy Journey-IRCTC"
```

Nine variables, walked left to right: `PNR:` `TRN:` `DOJ:` `FARE:` `DEP:` are fixed labels (each with its comma); `SC-TPTY` splits into `FromStation + "-" + ToStation`; the seat `S6-34` is one value (`SeatNo`) — the dash inside it belongs to the *value*, not the template. `.Happy Journey-IRCTC` is the same for every ticket.

**C2.**

```
print "Booking ID:" + BookingId + "," + MovieName + "," + TheatreName + ",Screen " + ScreenNo + ",Seats:" + SeatNos + "," + ShowDate + " " + ShowTime + ".Total Rs." + TotalAmount + ".Enjoy the movie!"
```

The interesting variable is `SeatNos`: its value is `D12,D13` — a **comma inside the value**. The template cannot split it into fixed text, because another customer books one seat or three. Date and time are glued with a plain `" "` between them.

---

# Part D — More Messages

**D1.**

```
print "Rs." + Amount + " transferred from A/c " + FromAccount + " to A/c " + ToAccount + " on " + Date + ". Ref No " + RefNo + ". Avl bal: Rs." + Balance + "."
```

The teaching point: **two values of the same kind need two different names.** Both `XX3401` and `XX8266` are account numbers, but they mean different things in this message — one money leaves, one money enters. `FromAccount` and `ToAccount` say which is which; calling them `AccountNo1` and `AccountNo2` loses the meaning.

**D2.**

```
print "Train " + TrainNo + " " + TrainName + " from " + FromCity + " to " + ToCity + " is delayed by " + DelayMinutes + " mins. Expected departure " + NewDepartureTime + " from platform " + PlatformNo + "."
```

Seven variables. `12727 GODAVARI EXP` is `TrainNo + " " + TrainName` — for another train both change, and the space between them is template. The cities are variables, not fixed text, because the same template serves the return train in the other direction. The space after `mins.` lives inside `" mins. Expected departure "`.
