def show_schedule(balance, y_rate, payment):
    m_rate = y_rate / 12.0
    i = 0
    total = 0
    while balance > 0:
        i = i + 1
        interest = int(balance * m_rate)
        pay = payment - interest
        if balance < pay:
            pay = balance
        total += pay
        total += interest
        balance -= pay
        print(f"{i} {interest} {pay} {interest + pay} {balance}")
    print(f"Total = {total}, {i} times")



def num_payment(balance, y_rate, payment):
    m_rate = y_rate / 12.0
    i = 0
    total = 0
    while balance > 0:
        i = i + 1
        interest = int(balance * m_rate)
        pay = payment - interest
        if balance < pay:
            pay = balance
        total += pay
        total += interest
        balance -= pay
        #print(f"{i} {interest} {pay} {interest + pay} {balance}")
    return i, total

def main():
    y_rate = 0.15  # Yearly rate
    payment = 10000  # Monthly payment
    b = [100000, 200000, 300000, 400000, 500000, 700000, 780000, 790000, 799999]
    for balance in b:
        n, total = num_payment(balance, y_rate, payment)
        print(balance, n, total)

if __name__ == '__main__':
    #main()
    show_schedule(100000,0.15, 10000)
