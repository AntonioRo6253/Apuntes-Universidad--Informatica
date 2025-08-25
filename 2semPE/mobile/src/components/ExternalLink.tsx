import { Href, Link } from "expo-router";
import { openBrowserAsync } from "expo-web-browser";
import { Platform } from "react-native";

export type Props = {
  href: string;
  children?: React.ReactNode;
};

const ExternalLink = ({
  href,
  children,
}: {
  href: string;
  children?: React.ReactNode;
}) => {
  return (
    <Link
      target="_blank"
      href={href as Href}
      onPress={async (event) => {
        if (Platform.OS !== "web") {
          // Prevent the default behavior of linking to the default browser on native.
          event.preventDefault();
          // Open the link in an in-app browser.
          await openBrowserAsync(href);
        }
      }}
    >
      {children}
    </Link>
  );
};

export { ExternalLink };
