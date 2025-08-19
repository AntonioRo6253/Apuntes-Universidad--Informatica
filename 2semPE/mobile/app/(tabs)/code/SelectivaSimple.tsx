import React, { useState, useEffect } from "react";
import { StyleSheet, ScrollView, TextInput } from "react-native";
import { ThemedView } from "@/components/ThemedView";
import { ThemedText } from "@/components/ThemedText";

export default function SelectivaSimple() {
  const [numero, setNumero] = useState<string>(""); // mantener como string (TextInput)
  const [resultado, setResultado] = useState<string>("Escuchando...");

  useEffect(() => {
    if (numero.trim() === "") {
      // Si no ahi nada en input ponemos setResultado como "Escuchando..."
      setResultado("Escuchando...");
      return; // Si no hay nada en el input, no hacemos nada y finalizamos con return
    }

    const numeroValue = Number(numero); // Transformamos numero a valor numerico
    if (!isNaN(numeroValue)) {
      // Checamos si es no es un numero y invertimos el resultado

      if (numeroValue > 0) {
        // es mayor a cero?
        setResultado(`${numeroValue} es mayor a cero`);
      } else if (numeroValue < 0) {
        // si no es mayor a cero, es menor a cero?
        setResultado(`${numeroValue} es menor a cero`);
      } else {
        // si no es ninguno de los anteriores, es igual a cero
        setResultado(`${numeroValue} es igual a cero`);
      }
    } else {
      setResultado("Por favor ingresa un número válido"); // numeroValue no es un dato valido
    }
  }, [numero]); // hacemos que useEffect esté al pendiente de cambios en numero
  //------------------------

  return (
    //----Renderizado
    <ScrollView style={styles.container} contentContainerStyle={styles.content}>
      <ThemedView style={styles.titleContainer}>
        <ThemedText type="title">Selectiva Simple y Doble</ThemedText>
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
        <TextInput //-------Entrada
          style={styles.input}
          value={numero}
          onChangeText={setNumero}
          placeholder="Escribe un número..."
          returnKeyType="done"
        />
        <ThemedText>Valor ingresado: {numero}</ThemedText>
        {/*------Salida*/}
        <ThemedText>Resultado: {resultado}</ThemedText>
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
