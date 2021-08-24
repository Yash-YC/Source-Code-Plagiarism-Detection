import psyco
psyco.full()

entrada = open('C-small.in')
saida = open('C-small.out', 'w')

quantidade_casos = int(entrada.readline().strip())
casos = []
for i in range(quantidade_casos):
    caso = entrada.readline().strip().split(' ')
    caso = [float(a) for a in caso]
    casos.append(caso)
entrada.close()

numero_caso = 1
for caso in casos:
    print caso
    resultado = caso[0] / caso[1] + 1
    saida.write('Case #%d: %.7f\n' % (numero_caso, resultado))
    numero_caso += 1
saida.close()