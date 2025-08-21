import {
  Text,
  View,
  StyleSheet,
  ScrollView,
  useColorScheme,
} from "react-native";
import Constants from "expo-constants";
import { useRouter } from "expo-router";

import WorkItem from "@/components/WorkItem";
import { Colors } from "@/constants/Colors";

const statusBarHeight = Constants.statusBarHeight ?? 0;

export default function Code() {
  const router = useRouter();
  const colorScheme = useColorScheme();
  const theme = Colors[colorScheme === "dark" ? "dark" : "light"];

  const styles = StyleSheet.create({
    container: {
      flex: 1,
      backgroundColor: theme.background, // ahora dependiente del tema
      paddingTop: 16 + statusBarHeight,
    },
    screenTitle: {
      fontSize: 30,
      fontWeight: "800",
      color: theme.accents[2], // mantiene el rosa neón en ambos temas
      paddingHorizontal: 16,
      marginBottom: 8,
      textShadowColor: theme.accents[0],
      textShadowOffset: { width: 0, height: 0 },
      textShadowRadius: 10, // glow
    },
    sectionTitle: {
      fontSize: 12,
      fontWeight: "700",
      color: theme.accents[3], // cian suave según tema
      paddingHorizontal: 16,
      marginTop: 8,
      marginBottom: 6,
      letterSpacing: 2,
      textTransform: "uppercase",
    },
    list: {
      backgroundColor: "transparent",
      marginVertical: 6,
      borderTopWidth: 0,
      paddingHorizontal: 0,
    },
  });

  return (
    <View style={styles.container}>
      <Text style={styles.screenTitle}>Programacion Estructurada</Text>

      <ScrollView
        style={styles.list}
        contentContainerStyle={{ paddingBottom: 24 }}
      >
        <Text style={styles.sectionTitle}>PRIMER BLOQUE</Text>

        <WorkItem
          numero={1}
          titulo="Selectiva Simple"
          descripcion="Ejercicios con If"
          onPress={() => router.push("/code/SelectivaSimpleDos")}
        />
        <WorkItem
          numero={2}
          titulo="Selectiva Simple y Doble"
          descripcion="Ejercicios con If y Else"
          onPress={() => router.push("/code/SelectivaSimple")}
        />
      </ScrollView>
    </View>
  );
}
