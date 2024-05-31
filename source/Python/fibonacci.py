def fibonacci(n):
    """
    인수로 들어온 n값 미만의 피보나치 수열을 출력하는 함수
    ex. 인수로 10 : 0, 1, 1, 2, 3, 5, 8
    ex. 인수로  5 : 0, 1, 1, 2, 3
    """
    a, b = 0, 1 # (a, b) = (0, 1)
    while a < n:
        print(a, end='. ')
        a, b = b, a+b
    print() # 개행


if __name__ == '__main__': # main 영역에서 수행될때 import될 때는 수행 X
    fibonacci(100)
    print(__name__, '에서 테스트함')