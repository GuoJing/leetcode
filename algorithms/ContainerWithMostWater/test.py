from time import sleep
import threading


global network_buffer
network_buffer = []
buff_total = 100


class A(object):
    data_per_second = 10

    def send(self, data):
        while 1:
            if len(network_buffer) >= buff_total:
                sleep(1)
            data = self._send(data)
            if not data:
                break

    def _send(self, data):
        t = data[:self.data_per_second]
        for i in t:
            network_buffer.append(i)
        data = data[self.data_per_second:]
        sleep(0.1)
        return data


class B(object):
    data_per_second = 5

    def receive(self):
        i = 0
        while 1:
            if not network_buffer:
                sleep(1)
                i = i + 1
            self._receive()

    def _receive(self):
        for i in range(self.data_per_second):
            if not network_buffer:
                break
            network_buffer.pop()
        sleep(0.1)


d = range(0, 1024)

a = A()
b = B()

t1 = threading.Thread(target=a.send, args=(d,))
t2 = threading.Thread(target=b.receive)

try:
    t1.start()
    t2.start()
except:
    t1.stop()
    t2.stop()
