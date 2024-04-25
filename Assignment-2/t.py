price = float(input("Enter the price: "))
vat = price + price * 0.07

if vat <= 10000:
    discount = vat * 0.05
else:
    discount = vat * 0.1

discounted_price = vat - discount
print("Discounted price:", discounted_price)
