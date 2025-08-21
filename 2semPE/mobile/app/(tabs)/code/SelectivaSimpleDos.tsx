import React, { useState, useEffect } from "react";
import { StyleSheet, ScrollView, TextInput } from "react-native";
import { ThemedView } from "@/components/ThemedView";
import { ThemedText } from "@/components/ThemedText";

export default function SelectivaSimple() {
  const [numero, setNumero] = useState<string>(""); // mantener como string (TextInput)
  const [numero2, setNumero2] = useState<string>(""); // mantener como string (TextInput)
  const [resultado, setResultado] = useState<string>("Escuchando...");

  useEffect(() => {
    if (numero.trim() === "") {
      // Si no ahi nada en input ponemos setResultado como "Escuchando..."
      setResultado("Escuchando...");
      return; // Si no hay nada en el input, no hacemos nada y finalizamos con return
    }

    const numeroValue = Number(numero); // Transformamos numero a valor numerico
    const numeroValue2 = Number(numero2); // Transformamos numero2 a valor numerico

    if (isNaN(numeroValue) || isNaN(numeroValue2)) {
      // Verificamos si ambos son números válidos
      setResultado("Por favor ingresa un número válido");
      return;
    }

    const resultados: string[] = []; // Iniciamos el string cadaves que ejecutamos useEffect para el resultado

    if (numeroValue > numeroValue2) {
      // Comparamos
      resultados.push(`${numeroValue} es mayor a ${numeroValue2}`); //Agregamos con .push al array nuestro mensaje
    }
    if (numeroValue < numeroValue2) {
      resultados.push(`${numeroValue} es menor a ${numeroValue2}`);
    }
    if (numeroValue === numeroValue2) {
      resultados.push(`${numeroValue} es igual a ${numeroValue2}`);
    }
    if (numeroValue >= numeroValue2) {
      resultados.push(`${numeroValue} es mayor o igual a ${numeroValue2}`);
    }
    if (numeroValue <= numeroValue2) {
      resultados.push(`${numeroValue} es menor o igual a ${numeroValue2}`);
    }

    // Formatear como lista con viñetas; mantener un mensaje por defecto si no hay ninguno
    const salida =
      resultados.length > 0 // Verificamos si tenemos elementos en la matriz
        ? resultados.map((r) => `• ${r}`).join("\n") // Si tenemos Elementos con map recorremos el array Recuerda, r = Elemento array
        : "Ninguna comparación verdadera"; // Si en el array ahi 0 elementos

    setResultado(salida);
  }, [numero, numero2]); // hacemos que useEffect esté al pendiente de cambios en numero y numero2
  //------------------------

  return (
    //----Renderizado
    <ScrollView style={styles.container} contentContainerStyle={styles.content}>
      <ThemedView style={styles.titleContainer}>
        <ThemedText type="title">Selectiva Doble</ThemedText>
      </ThemedView>

      <ThemedView style={styles.stepContainer}>
        <ThemedText>
          nos permite ejecutar un bloque de instrucciones (seguir un camino) en
          caso de que la condición a evaluar sea verdadera, si la condición a
          evaluar es falsa, entonces ese bloque de instrucciones no se ejecuta y
          continua la ejecución de la siguiente instrucción después de la
          estructura.
        </ThemedText>
      </ThemedView>

      <ThemedView style={styles.stepContainer}>
        <ThemedText type="subtitle">Ingresa un número</ThemedText>
        <TextInput //-------Entrada de numero 1
          style={styles.input}
          value={numero}
          onChangeText={setNumero}
          placeholder="Escribe un número..."
          returnKeyType="done"
        />
        <ThemedText type="subtitle">Ingresa el segundo número</ThemedText>
        <TextInput //-------Entrada de numero 2
          style={styles.input}
          value={numero2}
          onChangeText={setNumero2}
          placeholder="Escribe un número..."
          returnKeyType="done"
        />
        <ThemedText>Valor ingresado Numero 1: {numero}</ThemedText>
        <ThemedText>Valor ingresado Numero 2: {numero2}</ThemedText>

        {/*------Salida*/}
        <ThemedText>Resultado:</ThemedText>
        <ThemedText>{resultado}</ThemedText>
      </ThemedView>
    </ScrollView>
  );
}

const styles = StyleSheet.create({
  container: { flex: 1, backgroundColor: "transparent" },
  content: { padding: 16 },
  titleContainer: { marginBottom: 12 },
  stepContainer: { marginBottom: 24 },
  title: { fontSize: 18, fontWeight: "600", backgroundColor: "transparent" },
  input: {
    marginTop: 8,
    marginBottom: 12,
    paddingVertical: 8,
    paddingHorizontal: 12,
    borderRadius: 6,
    borderWidth: 1,
    borderColor: "#ccc",
    backgroundColor: "white",
  },
});
