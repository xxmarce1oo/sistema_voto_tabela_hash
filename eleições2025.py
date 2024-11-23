ids_eleitor = set()

votos = {}

def voto(id_eleitor, candidato):
    if id_eleitor in ids_eleitor:
        return "Eleitor já votou"
    ids_eleitor.add(id_eleitor)
    if candidato in votos:
        votos[candidato] += 1
    else:
        votos[candidato] = 1
    return "Voto computado para " + candidato

def resultado():
    if not votos:
        return "Nenhum voto computado"
    resultado = "Resultado da eleição:\n"
    for candidato in votos:
        resultado += f"Por unanimidade {candidato}: foi reeleito com {votos[candidato]} votos e será presidente do catei pelo 3° ano consecutivo! \n"
    return resultado

print(voto(1, "Marcelo Batista"))
print(voto(1, "Marcelo Batista"))
print(voto(3, "Marcelo Batista"))
print(voto(4, "Marcelo Batista"))
print(resultado())


    
