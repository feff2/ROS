import rclpy
from rclpy.node import Node
from std_msgs.msg import String
from geometry_msgs.msg import Twist

class TextToCmdVel(Node):
    def __init__(self):
        super().__init__('text_to_cmd_vel')

        # Подписка на топик с текстовыми командами
        self.subscription = self.create_subscription(
            String,
            'cmd_text',
            self.listener_callback,
            10
        )

        # Публикация в топик /turtle1/cmd_vel
        self.publisher = self.create_publisher(Twist, '/turtle1/cmd_vel', 10)

        # Определяем возможные команды
        self.commands = {
            "turn_right": self.turn_right,
            "turn_left": self.turn_left,
            "move_forward": self.move_forward,
            "move_backward": self.move_backward
        }

    def listener_callback(self, msg):
        command = msg.data.lower()  # Переводим команду в нижний регистр
        self.get_logger().info(f"Received command: {command}")
        
        # Выполняем соответствующую команду, если она существует
        if command in self.commands:
            self.commands[command]()
        else:
            self.get_logger().warn(f"Unknown command: {command}")

    def turn_right(self):
        twist = Twist()
        twist.angular.z = -1.5  # Поворачиваем вправо (по часовой)
        self.publisher.publish(twist)
        self.get_logger().info("Turning right")

    def turn_left(self):
        twist = Twist()
        twist.angular.z = 1.5  # Поворачиваем влево (против часовой)
        self.publisher.publish(twist)
        self.get_logger().info("Turning left")

    def move_forward(self):
        twist = Twist()
        twist.linear.x = 1.0  # Движемся вперед
        self.publisher.publish(twist)
        self.get_logger().info("Moving forward")

    def move_backward(self):
        twist = Twist()
        twist.linear.x = -1.0  # Движемся назад
        self.publisher.publish(twist)
        self.get_logger().info("Moving backward")

def main(args=None):
    rclpy.init(args=args)
    node = TextToCmdVel()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()

