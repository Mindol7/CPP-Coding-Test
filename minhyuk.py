import turtle
t = turtle.Turtle()
s = turtle.Screen()
s.bgcolor('skyblue')
import random

#행복아파트 그리기
t.penup()
t.goto(-150,300)
t.write("Warning. 폭탄을 제거하세요 !" , font = ('Times New Roman', 20, 'bold'))
def aptdraw():
    t.speed(0)
    t.penup()
    t.goto(-50,150)
    t.write("행복아파트" , font = ('Times New Roman', 16, 'bold'))
    t.goto(-200,-200)
    t.pendown()
    for i in range(4):
        t.width(5)
        t.forward(400)
        t.left(90)
    t.penup()
    t.goto(-150,-150)
    t.pendown()
    t.width(2)
    for i in range(2):
        t.forward(100)
        t.left(90)
        t.forward(50)
        t.left(90)
    t.penup()
    t.goto(50,-150)
    t.pendown()
    t.width(2)
    for i in range(2):
        t.forward(100)
        t.left(90)
        t.forward(50)
        t.left(90)
    t.penup()
    t.goto(-150,-50)
    t.pendown()
    t.width(2)
    for i in range(2):
        t.forward(100)
        t.left(90)
        t.forward(50)
        t.left(90)
    t.penup()
    t.goto(50,-50)
    t.pendown()
    t.width(2)
    for i in range(2):
        t.forward(100)
        t.left(90)
        t.forward(50)
        t.left(90)
    t.penup()
    t.goto(-150,50)
    t.pendown()
    for i in range(2):
        t.forward(100)
        t.left(90)
        t.forward(50)
        t.left(90)
    t.penup()
    t.goto(50,50)
    t.pendown()
    for i in range(2):
        t.forward(100)
        t.left(90)
        t.forward(50)
        t.left(90)
    #행복아파트 왼쪽 라인 호수 입력
    x1 = -112
    y1 = -125
    j = 101
    for i in range(3):
        t.penup()
        t.goto(x1,y1)
        t.pendown()
        t.write(j, font = ('bold', 12))
        j = j + 100
        y1 = y1 +100
    #행복아파트 오른쪽 라인 호수 입력
    x2 = 88
    y2 = -125
    j = 102
    for i in range(3):
        t.penup()
        t.goto(x2,y2)
        t.pendown()
        t.write(j, font = ('bold', 12))
        j = j + 100
        y2 = y2 +100


#폭탄 심기
apt_list = ['101', '102', '201', '202', '301', '302'] #아파트 호수들을 리스트를 통해 모음
def where_Boom():
    global Boom #Boom 변수를 전역함수로 설정하여 어디서든 사용가능하게함
    Boom = random.choice(apt_list) #random.choice 함수를 이용하여 apt_list에 있는 호수들중 한가지 부여
    detect()


#폭탄 찾기
    
def detect():
    global count
    count = 1
    while count<=3: #기회를 3번으로 한정
        choice = turtle.textinput("테러리스트의 메시지", '폭탄의 위치를 찾아봐라')
        if (choice != Boom):
            print("테러리스트 : '폭탄은 그곳에 숨겨져 있지않다. 넌 %d번의 기회가 남았다.'"%(3-count))
            count = count + 1
        else:
           break

#폭탄 해독 
def decode():
    print("테러리스트: '폭탄은 그곳에 숨겨져 있었다. 하지만 넌 암호 해독까지해야 폭탄을 제거할 수 있다.'")
    print("테러리스트: '암호는 총 3자리다.숫자로만 이루어져 있고, 이번에도 기회는 3번이니 신중히 암호를 해독하길 바란다.'")
    print("테러리스트: '힌트를 한가지 주자면 암호의 범위는 [100,120]이다.'")
    t.reset()
    Boom_draw()
    global password
    password = random.randint(100,120) #암호의 범위를 한정
    global pw_count
    pw_count = 1
    while pw_count <= 3:
        answer = turtle.textinput("암호입력칸", "암호를 입력하세요") #암호 입력 후 오답시 힌트를 주기 위해 크고 작음을 알려줌
        if (password > int(answer)):
            print("테러리스트 : '땡! 오답이다. 너의 암호는 답보다 작다. 넌 %d번의 기회가 남았다.'"%(3-pw_count))
            pw_count = pw_count + 1
        elif (password < int(answer)):
            print("테러리스트 : '땡! 오답이다. 너의 암호는 답보다 크다. 넌 %d번의 기회가 남았다.'"%(3-pw_count))
            pw_count = pw_count + 1
        else:
            break

#폭탄 그리기
def Boom_draw():
    t.speed(0)
    t.penup()
    t.goto(0,-100)
    t.begin_fill()
    t.color('black')
    t.circle(200)
    t.end_fill()
    t.goto(0,300)
    t.pendown()
    t.width(10)
    t.left(90)
    t.forward(50)
    t.right(90)
    t.forward(50)
    t.color('red')
    t.forward(30)
    t.left(180)
    t.forward(30)
    t.left(180)
    t.left(30)
    t.forward(30)
    t.left(180)
    t.forward(30)
    t.left(180)
    t.right(60)
    t.forward(30)
    t.left(30)
    t.penup()
    t.goto(-100,100)
    t.pendown()
    t.color('white')
    for i in range(2):
        t.forward(200)
        t.left(90)
        t.forward(50)
        t.left(90)
    t.penup()
    t.goto(-25,112)
    t.write("???", font = ('Times New Roman', 20))
    



#폭탄이 1단계에서 터짐
def explore():
    print("테러리스트: '폭탄의 위치는 %s에 있었다. 나의 테러는 성공적이군. 나를 잡도록 너희들은 노력해야할 것이다.'"%Boom)
    t.reset()
    s.bgcolor('red')
    aptdraw()
    t.penup()
    t.goto(-300,0)
    t.pendown()
    t.pencolor('blue')
    t.write("!!!!펑펑!!!!", font = ('바탕', 100))

#폭탄이 2단계에서 터짐
def explore2():
    print("테러리스트: '암호의 답은 %d였다. 1단계는 잘 해냈지만 2단계를 해결하지 못했군. 나의 테러는 성공적이군. 나를 잡도록 너희들은 노력해야할 것이다.'"%password)
    t.reset()
    s.bgcolor('red')
    aptdraw()
    t.penup()
    t.goto(-300,0)
    t.pendown()
    t.pencolor('blue')
    t.write("!!!!펑펑!!!!", font = ('바탕', 100))
    
    #폭탄을 제거함
def finish():
    print("테러리스트: '나의 테러를 이렇게 손쉽게 풀다니..실력이 엄청난 폭탄제거반이군.'")
    print("테러리스트: '다음번에는 더 어려운 난이도로 돌아오마. 그때까지 너희들도 실력을 지금보다 더 키울수 있도록.'")
    

aptdraw()
where_Boom()

#시스템 종료를 위한 import sys사용
import sys

if count == 4:
    explore()
    sys.exit()
else:
    decode()

if pw_count == 4:
    explore2()
else:
    finish()