import psyco
psyco.full()

entrada = open('A-small.in')
saida = open('A-small.out', 'w')

quantidade_casos = int(entrada.readline().strip())
casos = []
for i in range(quantidade_casos):
    caso = entrada.readline().strip().split(' ')
    caso = [int(a) for a in caso]
    casos.append(caso)

entrada.close()

numero_caso = 1

def convert10_to_base(number, base):
    chars = '0123456789'
    text = ''
    while number >= base:
        text = chars[number % base] + text
        number /= base
    text = chars[number] + text
    return text

def happy_in_base(number, base):
    if base == 2:
        return True
    a = 0
    b = convert10_to_base(number, base)
    tentativas = []
    while 1:
        for c in b:
            a += int(c) ** 2
        if a == 1:
            return True
        else:
            b = convert10_to_base(a, base)
            a = 0
            if b in tentativas:
                return False
            else:
                tentativas.append(b)

def testar_caso(bases):
    for i in xrange(2, 1000000):
        happy = True
        for base in bases:
            if base == 2:
                continue
            happy = happy_in_base(i, base)
            if not happy:
                break
        if happy:
            return i

for caso in casos:
    print caso
    resultado = testar_caso(caso)
    saida.write('Case #%d: %d\n' % (numero_caso, resultado))
    numero_caso += 1

saida.close()
