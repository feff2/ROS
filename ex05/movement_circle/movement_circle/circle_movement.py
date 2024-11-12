import math

from geometry_msgs.msg import Twist
import rclpy
from rclpy.node import Node

class RobotController(Node):

    def __init__(self):
        super().__init__('robot_controller')
        self.publisher = self.create_publisher(Twist, '/robot/cmd_vel', 1)
        self.timer = self.create_timer(0.1, self.on_timer)

        self.state = 0  # Состояние для управления движением
        self.side_length = 1.5  # Длина стороны квадрата
        self.diagonal_length = math.sqrt(2) * self.side_length  # Длина диагонали
        self.current_distance = 0.0  # Текущее пройденное расстояние
        self.current_angle = 0.0  # Текущий угол поворота
        self.cnt = 0  # Счетчик для поворотов

    def on_timer(self):
        msg = Twist()

        if self.state == 0:  # Движение вперед по квадрату
            msg.linear.x = 0.5
            self.current_distance += 0.5 * 0.1  # Обновляем пройденное расстояние
            if self.current_distance >= self.side_length:
                self.current_distance = 0.0
                self.state = 1

        elif self.state == 1:  # Поворот на 90 градусов
            msg.angular.z = math.pi / 2
            self.current_angle += math.pi / 2 * 0.1  # Обновляем текущий угол
            if self.current_angle >= math.pi / 2:
                self.current_angle = 0.0
                self.cnt += 1
                if self.cnt < 4:
                    self.state = 0
                else:
                    self.cnt = 0
                    self.state = 2

        elif self.state == 2:  # Движение по диагонали
            msg.linear.x = 0.5
            self.current_distance += 0.5 * 0.1  # Обновляем пройденное расстояние
            if self.current_distance >= self.diagonal_length:
                self.current_distance = 0.0
                self.state = 3

        elif self.state == 3:  # Поворот на 90 градусов после диагонали
            msg.angular.z = math.pi / 2
            self.current_angle += math.pi / 2 * 0.1  # Обновляем текущий угол
            if self.current_angle >= math.pi / 2:
                self.current_angle = 0.0
                self.state = 0

        self.publisher.publish(msg)

def main():
    rclpy.init()
    node = RobotController()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass

    rclpy.shutdown()

if __name__ == '__main__':
    main()
