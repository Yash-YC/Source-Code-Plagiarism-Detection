
def es_feliz(num, base, mayor, anteriores)
  nro = entero(num,base)
  #puts "num: #{num} - base: #{base} - nro #{nro} - anteriores: #{anteriores.to_s}"
  
  if anteriores.include?(nro) then
    #puts "rep"
    return false
  else
    anteriores << nro
  end
  caracteres = nro.to_s.split(//)
  r = 0
  caracteres.each do |i|
    vi = i.to_i
    r = r + vi*vi
  end
  if r ==1 then
    #puts "feliz"
    return true
  else
    return es_feliz(r, base, mayor, anteriores)
  end
end

def entero(valor, basez)
  if(basez.to_i != 10) then
    return valor.to_i.to_s(basez.to_i)
  end
  return valor.to_s
end

def resolver(cadena)
  numeros = cadena.split(/ /)
  
  base_mayor = numeros.last.to_i
  (base_mayor..1000000000000).each do |i|
    ok = true

    numeros.each do |bs|
      fl = es_feliz(i,bs,base_mayor, Array.new)

      if !fl then
        ok = false
        break
      end
    end

    if ok then
      return i
    end
  end
  0
end

#lectura del archivo
entrada = IO.readlines("entrada")
puts "Leidas #{entrada.length} lineas"

#procesamiento
salidas = []
casos = entrada[0].to_i

puts "Total de casos: #{casos}"

(1..casos).each do |i|
  cadena = entrada[i].chop
  res = resolver(cadena)
  puts "Cadena: #{cadena} - Resultado: #{res}"
  salidas << "Case \##{i}: #{res}"
end

#escritura de resultados
salida_archivo = File.open('salida', 'w')
salidas.each do |linea|
  salida_archivo.puts(linea)
end
salida_archivo.close
