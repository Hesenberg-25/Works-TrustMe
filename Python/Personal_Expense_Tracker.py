expenses=[]
print("="*100)
print("PERSONAL EXPENSE TRACKER".center(50))
print("="*100)
while True :
  print("="*100)
  print("1. ADD NEW EXPENSE")
  print("2. VIEW ALL EXPENSE")
  print("3. CATEGORY SUMMARY")
  print("4. BUGET TRACKER")
  print("5. SEARCH EXPENSE")
  print("6. EXIT")
  print("="*100)
  choice=int(input("ENTER YOUR CHOICE FROM (1-6) :"))
  categories=["FOOD","TRANSPORT","ENTERTAINMENT","BILLS","CLOTHES","OTHERS"]
  if choice == 1 :
#FOR OPTOIN NO 1
    print("✅ADD NEW EXPENSE FUNCTIONALITY")
    categories=["FOOD","TRANSPORT","ENTERTAINMENT","BILLS","CLOTHES","OTHERS"]
    categories_join=",".join(categories)
    print(f"AVAILABLE CHOICES : {categories_join }")
    category=input("ENTER THE DESIRED CATEGORY : ").upper()
    amount=float(input("ENTER THE AMOUNT SPENT : "))
    desc=input("ENTER THE DESCRIPTOIN : ").upper()
    print(f"CATEGORY IS {category}, AMOUNT SPENT IS {amount}, DESCRIPTION IS {desc}")
    expense={}
    expense["CATEGORY"]=category
    expense["AMOUNT"]=amount
    expense["DESC"]=desc
    expenses.append(expense)
#FOR OPTION NO 2
  elif choice==2 :
    print("--- ALL EXPENSES ---")
    count=1
    total=0
    for i in expenses:
      print(f"#{count} | {i['CATEGORY']} | {i['AMOUNT']} | {i['DESC']}" )
      count=count+1
      total=total+i["AMOUNT"]
    print("-"*50)
    print(f"YOUR TOTAL EXPENSES ARE : {total}")
# FOR OPTION NO 3
  elif choice==3:
    print("✅CATEGORY SUMMARY")
    food_total=0
    entertainment_total=0
    transport_total=0
    bills_total=0
    clothes_total=0
    other_total=0
    for i in expenses:
      item=i["CATEGORY"].upper()
      amount=i["AMOUNT"]
      if i["CATEGORY"]=="FOOD":
        food_total=food_total+i["AMOUNT"]
      elif i["CATEGORY"]=="TRANSPORT":
        transport_total=transport_total+i["AMOUNT"]
      elif i["CATEGORY"]=="ENTERTAINMENT":
         entertainment_total=entertainment_total+i["AMOUNT"]
      elif i["CATEGORY"]=="BILLS":
        bills_total=bills_total+i["AMOUNT"]
      elif i["CATEGORY"]=="CLOTHES":
         clothes_total=clothes_total+i["AMOUNT"]
      else:
          other_total=other_total+i["AMOUNT"]
    print(f"AMOUNT SPEND ON FOOD :{food_total}")
    print(f"AMOUNT SPEND ON TRANSPORT : {transport_total}")
    print(f"AMOUNT SPEND ON ENTER : {entertainment_total}")
    print(f"AMOUNT SPEND ON BILLS : {bills_total}")
    print(f"AMOUNT SPEND ON CLOTHES : {clothes_total}")
    print(f"AMOUNT SPEND ON OTHERS : {other_total}")
# FOR OPTION NO 4
  elif choice==4:
    budget=2000
    left=budget-total
    print(left)
    if left>0:
      print("YOU ARE UNDER BUDGET")
    else :
      print("YOU NEED TO MANAGE YOUR BUDGET")
# FOR OPTION NO 5
  elif choice==5:
    choice=input("ENTER THE TYPE BY WHICH YOU WANT TO SEARCH (CATEGORY,AMOUNT,DESC) : ").upper()
    if choice == "CATEGORY":
      select=input("ENTER THE CATEGORY : ").upper()
      for i in expenses :
        if i["CATEGORY"].upper()==select:
          print(i["CATEGORY"],i["AMOUNT"],i["DESC"])
    elif choice =="DESC":
      select=input("ENTR THE DESC : ").upper()
      for i in expenses:
        if i["DESC"].upper()==select:
          print(i["CATEGORY"],i["AMOUNT"],i["DESC"])
    elif choice =="AMOUNT":
      relate=input("ENTER WEATHER YOU WANT TO SEARCH GREATER/SMALLER/EQUAL : ").upper()
      select=int(input("ENTR THE AMOUNT : "))
      if relate=="GREATER":
         for i in expenses:
          if i["AMOUNT"]>=select:
            print(i["CATEGORY"],i["AMOUNT"],i["DESC"])
      elif relate=="SMALLER":
        for i in expenses:
         if i["AMOUNT"]>=select:
           print(i["CATEGORY"],i["AMOUNT"],i["DESC"])
      elif relate=="EQUAL":
        for i in expenses:
         if i["AMOUNT"]==select:
           print(i["CATEGORY"],i["AMOUNT"],i["DESC"])
# FOR OPTION NO 6
  elif choice==6:
    print("✅THANK YOU FOR VISITING")
    break
  else:
    print("INVALID OPTION, PLEASE TRY AGAIN")