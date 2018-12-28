from PIL import Image

spiralraw = open("outspiral.txt", "r")

data = spiralraw.readlines();

size = len(data)

pixels = []

out = Image.new("RGB", (size, size), color = 0)

pixels = out.load()

for i in range(size):
    for j in range(size):
        if data[i][j] is '0':
            pixels[i,j] = (255, 255, 255)

out.save("out.png", "PNG")
