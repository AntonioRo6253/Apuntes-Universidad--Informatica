import React, { useState, useEffect } from "react";
import { StyleSheet, ScrollView, TextInput } from "react-native";
import { ThemedView } from "@/src/components/ThemedView";
import { ThemedText } from "@/src/components/ThemedText";

/**
 * # Componente SelectivaSimple.
 *
 * Observa dos entradas de texto (números), valida y convierte los valores,
 * ejecuta las comparaciones mediante `main` y muestra los mensajes resultantes.
 *
 * ### Diagrama de flujo (mermaid):
 *
 * ```mermaid
 * graph TD
 *   Start(Usuario ingresa numeros) --> V{Inputs vacios o invalidos}
 *   V -- Si --> Err[Mostrar: Escuchando o por favor ingresa un numero valido]
 *   V -- No --> Call[LLamar main con numeroValue, numeroValue2, resultados]
 *   Call --> Format[Formatear resultados • ...]
 *   Format --> Show[Actualizar estado resultado y renderizar]
 *   Show --> End(Fin)
 * ```
 *
 * Estado interno:
 * - numero: string del primer TextInput.
 * - numero2: string del segundo TextInput.
 * - resultado: texto formateado con las comparaciones (puede contener varias líneas).
 *
 * @returns JSX.Element - Vista con inputs y el resultado de las comparaciones.
 *
 * # La función main
 *
 * Ejecuta comparaciones entre dos números y agrega mensajes descriptivos al array `resultados`.
 *
 * Añade mensajes para las siguientes comparaciones:
 * - mayor
 * - menor
 * - igual
 * - mayor o igual
 * - menor o igual
 *
 * Diagrama de flujo (mermaid):
 *
 * ```mermaid
 * flowchart TD
 *   Start[Inicio] --> C1{numeroValue > numeroValue2?}
 *   C1 -- Sí --> Push1["es mayor a ..."]
 *   C1 -- No --> C2{numeroValue < numeroValue2?}
 *   C2 -- Sí --> Push2["es menor a ..."]
 *   C2 -- No --> C3{numeroValue === numeroValue2?}
 *   C3 -- Sí --> Push3["es igual a ..."]
 *   C3 -- No --> C4{numeroValue >= numeroValue2?}
 *   C4 -- Sí --> Push4["es mayor o igual a ..."]
 *   C4 -- No --> C5{numeroValue <= numeroValue2?}
 *   C5 -- Sí --> Push5["es menor o igual a ..."]
 *   Push1 --> End["Fin"]
 *   Push2 --> End
 *   Push3 --> End
 *   Push4 --> End
 *   Push5 --> End
 * ```
 *
 */

export default function SelectivaSimple() {
  const [numero, setNumero] = useState<string>(""); // mantener como string (TextInput)
  const [numero2, setNumero2] = useState<string>(""); // mantener como string (TextInput)
  const [resultado, setResultado] = useState<string>("Escuchando...");
  /**
   * @param numeroValue - Primer número a comparar.
   * @param numeroValue2 - Segundo número a comparar.
   * @param resultados - Array donde se añaden los mensajes; se modifica in-place.
   * @returns void
   */
  function main(
    numeroValue: number,
    numeroValue2: number,
    resultados: string[]
  ) {
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
  }

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

    main(numeroValue, numeroValue2, resultados);

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
