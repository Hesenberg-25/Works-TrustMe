def create_order(customer_name, *items, **order_details):
    """Process an Indian restaurant order with flexible items and options"""
    print(f"\n🍛 --- Order for {customer_name} ---")
    print("Items ordered:")
    
    total_price = 0
    
    # Indian menu prices (in rupees)
    menu_prices = {
        # Main dishes
        "dal_tadka": 180, "paneer_butter_masala": 280, "chicken_curry": 320,
        "mutton_curry": 380, "fish_curry": 350, "rajma": 200,
        "chole": 190, "aloo_gobi": 160, "bhindi_masala": 170,
        "palak_paneer": 260, "kadhai_paneer": 270, "chicken_tikka_masala": 340,
        
        # Rice and bread
        "basmati_rice": 120, "jeera_rice": 140, "biryani": 280,
        "veg_biryani": 240, "chicken_biryani": 320, "mutton_biryani": 380,
        "roti": 20, "naan": 40, "garlic_naan": 50, "butter_naan": 45,
        "paratha": 35, "kulcha": 45,
        
        # Starters
        "samosa": 30, "pakora": 120, "paneer_tikka": 220,
        "chicken_tikka": 280, "tandoori_chicken": 300,
        
        # Beverages
        "masala_chai": 25, "lassi": 60, "mango_lassi": 70,
        "fresh_lime": 40, "buttermilk": 35,
        
        # Desserts
        "gulab_jamun": 80, "rasgulla": 70, "kheer": 90, "kulfi": 60
    }
    
    for item in items:
        price = menu_prices.get(item, 100)  # default price ₹100
        total_price += price
        display_name = item.replace('_', ' ').title()
        print(f"  - {display_name}: ₹{price}")
    
    if order_details.get('extra_ghee'):
        print("  + Extra ghee: ₹20")
        total_price += 20
    
    if order_details.get('less_spicy'):
        print("  + Less spicy (noted)")
    elif order_details.get('extra_spicy'):
        print("  + Extra spicy (noted)")
        
    if order_details.get('no_onion'):
        print("  + No onion (noted)")
        
    if order_details.get('jain_food'):
        print("  + Jain food preparation (noted)")
        
    if order_details.get('extra_pickle'):
        print("  + Extra pickle: ₹15")
        total_price += 15
        
    if order_details.get('extra_papad'):
        print("  + Extra papad: ₹25")
        total_price += 25
		
    delivery_type = order_details.get('delivery', 'pickup')
    tip = order_details.get('tip', 0)
    
    if delivery_type == 'home_delivery':
        print("  + Home delivery charges: ₹30")
        total_price += 30
    elif delivery_type == 'zomato':
        print("  + Zomato delivery charges: ₹40")
        total_price += 40
    elif delivery_type == 'swiggy':
        print("  + Swiggy delivery charges: ₹35")
        total_price += 35
    
    payment_method = order_details.get('payment', 'cash')
    if payment_method == 'online' and order_details.get('discount_coupon'):
        discount = total_price * 0.1  # 10% discount
        print(f"  - Online payment discount (10%): -₹{discount:.0f}")
        total_price -= discount
    
    total_price += tip
    
    print(f"\nSubtotal: ₹{total_price:.0f}")
    gst = total_price * 0.05
    total_with_gst = total_price + gst
    print(f"GST (5%): ₹{gst:.0f}")
    print(f"Total Amount: ₹{total_with_gst:.0f}")
    
    print(f"Order type: {delivery_type.replace('_', ' ').title()}")
    print(f"Payment method: {payment_method.upper()}")
    
    # Estimated time
    estimated_time = order_details.get('estimated_time', '25-30 minutes')
    print(f"Estimated time: {estimated_time}")

var = int(input("Please select which order you want to do 1 - 5 "))
if var == 1:
    create_order("Sharma Family", 
             "dal_tadka", "paneer_butter_masala", "roti", "roti", "roti", "basmati_rice",
             less_spicy=True)
elif var == 2:
    create_order("TechCorp Office", 
             "chicken_biryani", "chicken_biryani", "veg_biryani", 
             "paneer_tikka", "garlic_naan", "garlic_naan", "rasgulla",
             delivery="swiggy", 
             extra_spicy=True, 
             tip=50,
             estimated_time="45-50 minutes")

elif var == 3:
# Order 3: customer with specific requirements
    create_order("Rajesh",
             "dal_tadka", "aloo_gobi", "roti", "roti", "jeera_rice", "masala_chai",
             jain_food=True,
             no_onion=True,
             extra_pickle=True,
             extra_papad=True,
             payment="online",
             discount_coupon=True)
elif var == 4:
# Order 4: Quick snack order
    create_order("Priya",
             "samosa", "samosa", "pakora", "masala_chai", "masala_chai",
             delivery="pickup")

elif var == 5:
# Order 5: Special dinner with customizations
    create_order("Kumar",
             "mutton_curry", "chicken_tikka", "butter_naan", "garlic_naan", 
             "biryani", "kulfi", "mango_lassi",
             extra_ghee=True,
             less_spicy=True,
             delivery="home_delivery",
             payment="online",
             tip=100,
             estimated_time="40-45 minutes")
else:
    print("Oops Wrong Selection aj Fast hi karo aap !!! ")