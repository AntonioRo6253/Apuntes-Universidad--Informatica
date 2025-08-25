import { StyleSheet } from "react-native";
import ParallaxScrollView from "@/src/components/ParallaxScrollView";

import { ThemedText } from "@/src/components/ThemedText";
import { ThemedView } from "@/src/components/ThemedView";

export default function HomeScreen() {
  return (
    <ParallaxScrollView
      headerBackgroundColor={{ light: "#ffffff", dark: "#000000" }}
    >
      <ThemedView style={styles.titleContainer}>
        <ThemedText type="title">Programación Estructurada</ThemedText>
      </ThemedView>

      <ThemedView style={styles.stepContainer}>
        <ThemedText type="subtitle">Curso: V0716</ThemedText>
        <ThemedText>
          Repositorio con los ejercicios y prácticas del curso. El material
          sigue el libro de Luis Joyanes Aguilar y está organizado por temas y
          ejercicios.
        </ThemedText>
      </ThemedView>

      <ThemedView style={styles.stepContainer}>
        <ThemedText type="subtitle">Temas principales</ThemedText>
        <ThemedText>{`• Abstracción y modularidad`}</ThemedText>
        <ThemedText>{`• Funciones y procedimientos`}</ThemedText>
        <ThemedText>{`• Paso de parámetros (valor y referencia)`}</ThemedText>
        <ThemedText>{`• Arreglos y matrices`}</ThemedText>
        <ThemedText>{`• Registros y apuntadores`}</ThemedText>
        <ThemedText>{`• Manejo de memoria dinámica y recursividad`}</ThemedText>
      </ThemedView>

      <ThemedView style={styles.stepContainer}>
        <ThemedText type="subtitle">Cómo usar este proyecto</ThemedText>
        <ThemedText>
          Abre la carpeta del proyecto en VS Code y navega a la carpeta de
          ejercicios (por ejemplo, src o exercises). Para abrir en VS Code,
          desde la raíz del repo ejecuta:
        </ThemedText>
        <ThemedText type="defaultSemiBold">code .</ThemedText>
        <ThemedText>
          Para compilar y ejecutar los ejercicios en C desde la terminal
          (Linux):
        </ThemedText>
        <ThemedText type="defaultSemiBold">
          gcc archivo.c -o programa && ./programa
        </ThemedText>
      </ThemedView>

      <ThemedView style={styles.stepContainer}>
        <ThemedText type="subtitle">Consejos</ThemedText>
        <ThemedText>{`• Lee el enunciado del ejercicio antes de modificar el código.`}</ThemedText>
        <ThemedText>{`• Mantén cada ejercicio en archivos separados y bien comentados.`}</ThemedText>
        <ThemedText>{`• Usa git para controlar versiones y conservar ejercicios resueltos.`}</ThemedText>
      </ThemedView>
    </ParallaxScrollView>
  );
}

const styles = StyleSheet.create({
  container: {
    paddingHorizontal: 16,
    paddingBottom: 24,
  },
  titleContainer: {
    flexDirection: "row",
    alignItems: "center",
    gap: 8,
  },
  stepContainer: {
    gap: 8,
    marginBottom: 8,
  },
});
