import serial
import numpy as np
import cv2

# 配置串口
ser = serial.Serial('COM3', 115200, timeout=1)  # 请根据实际情况修改COM口

# 图像参数
width = 160
height = 120
image_size = width * height

while True:
    img_data = ser.read(image_size)  # 读取图像数据
    if len(img_data) == image_size:
        # 将字节数据转换为numpy数组并显示图像
        img = np.frombuffer(img_data, dtype=np.uint8).reshape((height, width))
        cv2.imshow('Received Image', img)
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break

ser.close()
cv2.destroyAllWindows()